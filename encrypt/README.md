# encrypt

`encrypt` is a straightforward wrapper library built on top of the OpenSSL library, offering implementations of cryptographic algorithms such as SHA-512 hashing and AES-256-CBC encryption.

## Features

- Efficient implementation of SHA-512 hashing.
- Implementation of AES-256-CBC encryption with OpenSSL.
- Utilizes `std::span` for handling input and output data efficiently.

## Usage

### SHA512

To compute the SHA-512 hash of a message, you can use the `SHA512` class:

```cpp
#include "encrypt/hash/SHA512.hpp"

using namespace encrypt;

int main() {
    std::string message = "Hello, World!";
    SHA512 sha512;
    std::string hash = sha512.hash({message.begin(), message.end()});
    std::cout << "SHA-512 hash of '" << message << "': " << hash << std::endl;
    return 0;
}
```
### AES256CBC
To perform AES-256-CBC encryption and decryption, you can use the `AES256CBC` class:

```cpp
#include "encrypt/symCrypt/AES256CBC.hpp"

using namespace encrypt;

int main() {
    std::string key = "YourKeyHere";
    std::string iv = "YourInitializationVectorHere";
    AES256CBC aes256cbc({iv.begin(), iv.end()});

    std::string plaintext = "YourPlainTextHere";
    std::string ciphertext(plaintext.size() + AES_BLOCK_SIZE, '\0');

    // Encryption
    aes256cbc.encrypt(key, {plaintext.begin(), plaintext.end()}, {ciphertext.begin(), ciphertext.end()});
    std::cout << "Encrypted text: " << ciphertext << std::endl;

    // Decryption
    std::string decryptedtext(plaintext.size(), '\0');
    aes256cbc.decrypt(key, {ciphertext.begin(), ciphertext.end()}, {decryptedtext.begin(), decryptedtext.end()});
    std::cout << "Decrypted text: " << decryptedtext << std::endl;

    return 0;
}
```
