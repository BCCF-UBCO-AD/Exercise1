#include "files.h"

void getFiles(std::string directory, std::vector<fs::path> &files) {
    unsigned int count = 0;
    unsigned int max = 0xFF;
    auto root = fs::u8path(directory);
    if (fs::is_directory(root)) {
        fs::recursive_directory_iterator recursive_iter(root);
        for (auto &entry: recursive_iter) {
            if (++count < max) {
                files.push_back(entry.path());
            } else {
                break;
            }
        }
    }
}
