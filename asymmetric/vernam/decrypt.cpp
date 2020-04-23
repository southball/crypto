#include "../../utility/helper.hpp"
#include "vernam.hpp"
#include <iostream>
#include <ostream>
#include <cassert>

Vernam vernam;
Vernam::KeyType key;
Vernam::PlainTextType plaintext;
Vernam::CipherTextType ciphertext;

int main() {
    program_title("Vernam Cipher Decryption");

    std::cout << "Enter ciphertext (0-1 string): ";
    std::cin >> plaintext;
    std::cout << "Enter key (0-1 string):        ";
    std::cin >> key;

    plaintext = vernam.Dec(plaintext, key);

    std::cout << "Plaintext:                     " << plaintext << std::endl;
}
