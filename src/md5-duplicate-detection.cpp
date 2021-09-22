#include "md5-duplicate-detection.h"

bool is_data_duplicate(fs::path& A, fs::path& B){
    std::fstream fileA(A);
    std::fstream fileB(B);
    size_t A_size = fs::file_size(A);
    size_t B_size = fs::file_size(B);
    char* A_buffer = new char[A_size];
    char* B_buffer = new char[B_size];
    fileA.read(A_buffer,A_size);
    fileB.read(B_buffer,B_size);
    return md5(A_buffer) == md5(B_buffer);
}