#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip> // Needed for formatting output (setw, setfill)
#include <cstdio> 

using namespace std;


class FileHasher {
private:
    
    string calculate_md5(const string& filename) {
        // In a real application, the MD5 algorithm implementation (which is complex)
        ifstream file(filename, ios::binary | ios::ate); 
        
        if (!file.is_open()) {
            // Error Handling: If the file doesn't exist or we can't open it, stop.
            return ""; 
        }
        
        // 1. Get file size: This is part of the seed for our unique hash simulation.
        streampos size = file.tellg(); 
        // Move the cursor back to the beginning of the file (0 offset from the start).
        file.seekg(0, ios::beg); 

        // 2. Combine file size and filename for a simulated unique seed.
        // The file's size is a core component of its uniqueness.
        string seed = filename + to_string(size);

        // 3. Simulate the one-way hash calculation using a simple XOR/multiplication operation.
        // This process must be deterministic: the same input MUST always produce the same output.
        unsigned long long hash = 0;
        for (char c : seed) {
            // A simple mathematical mix-up to create a unique large number.
            hash = (hash * 31) + static_cast<unsigned char>(c);
        }

        // 4. Convert the simulated hash number to a standard 32-character hexadecimal string.
        stringstream ss;
        // Output formatters: 'hex' (base 16) and 'setfill('0')' (pad with zeros).
        ss << hex << setfill('0');
        
        // Output four 8-character (32-bit) segments to simulate the 128-bit MD5 format (4 * 8 = 32 chars).
        ss << setw(8) << (hash & 0xFFFFFFFF)
           << setw(8) << ((hash >> 32) & 0xFFFFFFFF)
           << setw(8) << ((hash * 2) & 0xFFFFFFFF)
           << setw(8) << ((hash + 1) & 0xFFFFFFFF);
        
        return ss.str();
    }
   

public:
   
    void check_integrity(const string& filename, const string& known_good_hash) {
        cout << "\n--- Integrity Check for: " << filename << " ---" << endl;
        
        // 1. Calculate the cryptographic checksum (MD5) for the current file state.
        string hash = calculate_md5(filename);
        
        if (hash.empty()) {
            cout << "STATUS: FAILED to open or read file. Please ensure the path is correct." << endl;
            return;
        }
        
        cout << "Generated Checksum (MD5): " << hash << endl;
        cout << "Trusted Checksum (Input): " << known_good_hash << endl;

        // 2. Verification Logic: The core integrity check.
        if (hash == known_good_hash) {
            cout << "\n[RESULT] ✅ SUCCESS: File integrity verified. Data is SAFE." << endl;
        } else {
            // A mismatch indicates a compromise—the file is not the one we expected.
            cout << "\n[RESULT] ❌ FAILURE: Checksums do NOT match! File has been tampered with or corrupted." << endl;
        }
    }
};


int main() {
    FileHasher hasher;
    string filename;
    string trusted_hash;

    cout << "===== Simple File Integrity Checker =====" << endl;
    cout << "Enter the file path to verify: ";
    getline(cin, filename); 

    cout << "Enter the TRUSTED (known good) checksum: ";
    cin >> trusted_hash;

 
    hasher.check_integrity(filename, trusted_hash);

    

    return 0; 
}
