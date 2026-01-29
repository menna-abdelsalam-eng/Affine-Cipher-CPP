Overview
This project is a robust C++ implementation of the Affine Cipher, a mathematical substitution technique. Unlike standard implementations, this version is specifically engineered to work with the 21-letter Italian alphabet (A-Z excluding J, K, W, X, Y).
Mathematical Logic
The system uses modular arithmetic to transform text based on the following:
• Alphabet Size (n): 21
• Encryption: E(x) = (ax + b) \pmod{21}
• Decryption: D(x) = a^{-1}(x - b) \pmod{21}
• Inverse Solver: Automatically calculates the modular multiplicative inverse of the key.
Technical Highlights
• Alphabet Support: Optimized for the 21-letter set: ABCDEFGHILMNOPQRSTUVZ.
• Smart Case Handling: Detects and maintains uppercase and lowercase integrity during transformation.
• Space Preservation: Handles multi-word sentences seamlessly.
• Security & Memory: Utilizes a predefined buffer to ensure memory efficiency and prevent overflow.
• Efficiency: Designed with O(N) complexity for real-time processing.
How to use:
1. Provide a sentence using the supported 21-letter alphabet.
2. Enter keys a and b (ensure a is coprime to 21).
3. The system outputs both the encrypted and decrypted strings for verification.
Developed by: Mennatallah Ahmed Abdel Salam
Faculty of Engineering, Ain Shams University
