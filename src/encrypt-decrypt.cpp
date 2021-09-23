#include "encrypt-decrypt.h"

using namespace std;

char curr;

// Random key used for encryption/decryption
int key = 214748;

void encrypt(fs::path &input) {
    fstream finput;

    finput.open(input, fstream::in | fstream::out);
    if (!finput) {
        cout << "Input file not found. \n";
        return;
    }

    // Encrypt each character in-place
    while (finput >> noskipws >> curr) {
        int temp = (curr + key);
        finput.seekp((finput.tellp() - static_cast<streampos>(1)));
        finput.put((char) temp);
        finput.seekp(finput.tellp());
    }

    finput.close();

    std::cout << "Encryption complete. Output can be found in " << input.filename() << "\n";
}

void decrypt(fs::path &input) {
    fstream finput;

    finput.open(input, fstream::in | fstream::out);
    if (!finput) {
        cout << "Input file not found. \n";
        return;
    }

    // Decrypt each character in-place
    while (finput >> noskipws >> curr) {
        int temp = (curr - key);
        finput.seekp((finput.tellp() - static_cast<streampos>(1)));
        finput.put((char) temp);
        finput.seekp(finput.tellp());
    }

    finput.close();

    std::cout << "Decryption complete. Output can be found in " << input.filename() << "\n";
}