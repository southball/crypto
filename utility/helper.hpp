#pragma once

#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <vector>
#include <cassert>
#include <random>

/**
 * Note: this function is unsafe for cryptographic applications, and is only for demonstration purposes.
 */
template<class T>
T random_int(const T& min, const T& max) {
    static thread_local std::mt19937_64 generator(std::random_device{}());
    std::uniform_int_distribution<T> distribution(min, max);
    return distribution(generator);
}

void program_title(const std::string& title) {
    std::cout << title << std::endl;
    std::cout << std::endl;
}

// Helper for outputting vector<bool>.
std::ostream& operator<<(std::ostream& out, const std::vector<bool>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        out << (vec[i] ? '1' : '0');
    }
    return out;
}

// Helper for inputting vector<bool>.
std::istream& operator>>(std::istream& in, std::vector<bool>& vec) {
    std::string buf;
    in >> buf;

    int n = buf.length();
    vec.resize(n);

    for (int i = 0; i < n; i++) {
        assert(buf[i] == '0' || buf[i] == '1');
        vec[i] = buf[i] == '1';
    }
}