#include "encrypt-decrypt.h"

using namespace std;

char curr;

// Random key to use for encryption/decryption
int key = 214748;

void encrypt(fs::path &input, fs::path &output) {
    fstream finput, foutput;

    finput.open(input, fstream::in);
    if (!finput) {
        cout << "Input file not found. \n";
        return;
    }

    foutput.open(output, fstream::out);
    if (!foutput) {
        cout << "An error occurred when creating output file. \n";
        return;
    }

    while (finput >> noskipws >> curr) {
        int temp = (curr + key);
        foutput << (char) temp;
    }

    finput.close();
    foutput.close();

    std::cout << "Encryption complete. Output can be found in " << output.filename() << "\n";
}