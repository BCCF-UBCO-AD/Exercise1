#include <iostream>
#include <cassert>
#include "common.h"
#include "md5-duplicate-detection.h"

int main(){
    fs::path A("test-files/A"), B("test-files/B"), E("test-files/E");
    assert(is_data_duplicate(A,B));
    assert(!is_data_duplicate(A,E));
    std::cout << "test passed\n";
}