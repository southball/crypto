#include "../../utility/helper.hpp"
#include "vernam.hpp"
#include <iostream>
#include <ostream>
#include <cassert>

// Length of key, plaintext and ciphertext
int n;
Vernam vernam;
Vernam::KeyType key;
Vernam::PlainTextType plaintext;
Vernam::CipherTextType ciphertext;

int main() {
    program_title("Vernam Cipher Encryption");

    std::cout << "Enter plaintext (0-1 string): ";
    std::cin >> plaintext;

    n = plaintext.size();

    key = vernam.KeyGen(n);
    ciphertext = vernam.Enc(plaintext, key);

    std::cout << "Key:                          " << key << std::endl;
    std::cout << "Ciphertext:                   " << ciphertext << std::endl;
}
