#pragma once

#include "../../utility/helper.hpp"
#include <vector>
#include <cstdlib>

struct Vernam {
    using KeyType = std::vector<bool>;
    using PlainTextType = std::vector<bool>;
    using CipherTextType = std::vector<bool>;

    KeyType KeyGen(int length) {
        std::vector<bool> key(length);
        for (int i = 0; i < length; i++)
            key[i] = random_int(0, 1);
        return key;
    }

    CipherTextType Enc(PlainTextType plaintext, KeyType key) {
        assert(plaintext.size() == key.size());

        CipherTextType ciphertext(plaintext.size());
        
        for (int i = 0; i < plaintext.size(); i++)
            ciphertext[i] = plaintext[i] ^ key[i];
        
        return ciphertext;
    }

    PlainTextType Dec(CipherTextType ciphertext, KeyType key) {
        assert(ciphertext.size() == key.size());
        
        PlainTextType plaintext(ciphertext.size());

        for (int i = 0; i < ciphertext.size(); i++)
            plaintext[i] = ciphertext[i] ^ key[i];
        
        return plaintext;
    }
};
