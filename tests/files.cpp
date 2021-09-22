#include "common.h"
#include <cassert>
#include "files.h"

int main() {
    std::vector<fs::path> filepaths;
    std::vector<fs::path> testfilepaths;
    testfilepaths.push_back(fs::path("test-files/A"));
    testfilepaths.push_back(fs::path("test-files/B"));
    testfilepaths.push_back(fs::path("test-files/E"));

    getFiles("test-files/", filepaths);

    assert(filepaths == testfilepaths);
    std::cout << "test passed\n";
}