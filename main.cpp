#include <iostream>
#include "common.h"
#include "md5-duplicate-detection.h"
#include "encrypt-decrypt.h"
#include "files.h"

int main(int argc, char* argv[]) {

    int opt;

    while ((opt = getopt(argc, argv, "hedf")) != -1){ //getopt creates a data-structure that can be looped through from the argv array to process the parameters and their arguments

        switch (opt)
        {
            case 'h':
                printf("help command\n");    //placeholder
                break;
            case 'e':
                printf("encrypt\n");         //placeholder
                break;
            case 'd':
                printf("decrypt\n");         //placeholder
                break;
            case 'f':
                printf("file path param\n"); //file path
                break;
            case 1:
                printf("no arguments\n");    //default non-argument case
                break;
        }
    }

    /*
    std::string directory = "some directory";
    std::vector<fs::path> files;
    getFiles(directory, files);
    for (fs::path i: files)
     std::cout << i.string() << ' ';
     */

    //    fs::path A("test-files/A");
    //    fs::path B("test-files/B");
    //    is_data_duplicate(A,B);

    //    fs::path input("test-files/file.txt");
    //    encrypt(input);
    //    decrypt(input);

    return 0;
}
