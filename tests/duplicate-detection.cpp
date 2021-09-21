#include <iostream>
#include "common.h"
#include "md5-duplicate-detection.h"

int main(){
    fs::path A("test-files/A"), B("test-files/B"), E("test-files/E");
    if(is_data_duplicate(A,B)){
        std::cout << "Files A == B\n";
    } else {
        std::cout << "Files A != B\n";
    }

    if(is_data_duplicate(A,E)){
        std::cout << "Files A == E\n";
    } else {
        std::cout << "Files A != E\n";
    }
}