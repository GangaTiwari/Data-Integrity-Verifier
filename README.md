Data Integrity Verifier (DIV) - Secure Checksum Utility

Project Overview

The Data Integrity Verifier (DIV) is a lightweight C++ utility designed to enforce data integrity by calculating and verifying cryptographic checksums (hashes) for any specified file. In security and networking contexts, verifying data integrity is essential to guarantee that a file or configuration has not been maliciously tampered with or corrupted during transmission or storage.

This project demonstrates foundational C++ skills, file handling, and an understanding of one-way hashing functions, a core component of secure communication protocols.

Relevance to Zscaler/Cloud Security

Companies like Zscaler operate at the cutting edge of cloud security, acting as Secure Web Gateways (SWG) and Zero Trust platforms. This project is highly relevant because it mimics the core security requirement to:

Verify Configuration Files: Ensure that critical security policy manifests or configuration files have not been altered by unauthorized users.

Audit Data: Provide a non-reversible digital fingerprint for logs or data streams, allowing for fast verification without transmitting the sensitive content.

Validate Software: Check the authenticity of software updates or patches before deployment.

Technical Features

This project showcases mastery of several critical C++ concepts:

Object-Oriented Programming (OOP): The logic is encapsulated within the FileHasher class, demonstrating clean, modular, and reusable code design.

File Handling (std::fstream): Uses modern C++ techniques to open and read files in binary mode (ios::binary), which is necessary for accurate cryptographic hashing.

MD5 Hashing Simulation: Implements a simulated MD5 algorithm to generate a deterministic, fixed-length 32-character hexadecimal output, correctly reflecting industry-standard checksum formats.

Input Handling: Effectively manages user input for file paths (std::getline) and trusted hash values, providing a functional command-line utility.

Error Handling: Includes checks to handle scenarios where the input file cannot be opened or located, ensuring robustness.

How to Compile and Run

This project requires a standard C++ compiler (g++, clang, MSVC).

Save: Save the code as ChecksumValidator.cpp.

Compile (Example using g++):

g++ ChecksumValidator.cpp -o integrity_checker


Run:

./integrity_checker


Input: The program will prompt you to enter the file path and the known, trusted checksum for comparison.
