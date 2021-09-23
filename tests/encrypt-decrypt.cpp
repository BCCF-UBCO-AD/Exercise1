#include <iostream>
#include <cassert>
#include "common.h"
#include "md5-duplicate-detection.h"
#include "encrypt-decrypt.h"

int main(){
    fs::path input("test-files/file.txt");
    fs::path encryptedOutput("test-files/file_encrypted.txt");
    fs::path decryptedOutput("test-files/file_decrypted.txt");

    encrypt(input, encryptedOutput);
    assert(!is_data_duplicate(input, encryptedOutput));

    decrypt(encryptedOutput, decryptedOutput);
    assert(is_data_duplicate(input,decryptedOutput));
    std::cout << "test passed\n";
}