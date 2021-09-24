#include <iostream>
#include <getopt.h>
#include "common.h"
#include "md5-duplicate-detection.h"
#include "encrypt-decrypt.h"
#include "files.h"

int main(int argc, char *argv[]) {

    int opt, option_index = 0, eord = -1;
    const char *directory;
    std::vector<fs::path> files;
    struct option long_options[] =
            {
                    {"help",     no_argument, NULL,  'h' },
                    {"encrypt",  no_argument, NULL,  'e' },
                    {"decrypt",  no_argument, NULL,  'd' },
                    {NULL,      0,    NULL,   0  }
            };

    auto parsing = [&](){
        opt = getopt_long(argc, argv, "he:d:f:", long_options, &option_index);
        return opt != -1;
    };
    while (parsing()) { //getopt creates a data-structure that can be looped through from the argv array to process the parameters and their arguments

        switch (opt) {
            case 'h':
                printf("Usage: ex1 [OPTION]...[\"DIRECTORY\"]..\n"
                       "Used to encrypt and decrypt directories given a root path as the argument. You can only\n"
                       "use on argument at a time encrypt or decrypt\n\n"
                       "options:\n"
                       "-e, --encrypt               | Encrypts files in a given directory and accepts the root path as an argument \n"
                       "-d, --decrypt               | Decrypts encrypted files from this program and accepts the root path as an argument\n"
                       "-f                          | Checks for duplicate files in a directory\n"
                       "-h, --help                  | Prints help message\n"
                );    //placeholder
                break;
            case 'e':
                directory = optarg;
                if (eord < 0) {
                    eord = 0;
                }else{
                    eord = 2;
                }
                break;
            case 'd':
                directory = optarg;
                if (eord < 0) {
                    eord = 1;
                }else{
                    eord = 2;
                }
                break;
            case 'f':
                directory = optarg;
                if (eord < 0) {
                    eord = 3;
                }else{
                    eord = 2;
                }
                break;
            default:
                std::cout << "Invalid Option: " << opt << "\nNo arguments found use -h to see usage information" << std::endl;    //default non-argument case
                break;
        }
    }

    getFiles(directory, files);

    if(eord == 0){
        for (fs::path &file: files) {
            encrypt(file);
            std::cout << "Encrypted " << file.string() << "\n";
        }
    }else if(eord == 1){
        for (fs::path &file: files) {
            decrypt(file);
            std::cout << "Decrypted " << file.string() << "\n";
        }
    }else if(eord == 2){
        std::cout << "Must choose either encrypt or decrypt or file duplication check" << std::endl;
    }else if(eord ==3){

        for(int f1 = 0; f1 < files.size(); ++f1){
            for(int f2 = f1 + 1; f2 < files.size(); ++f2) {
                if(is_data_duplicate(files[f1], files[f2] )){
                    std::cout << files[f1].string() << " and " << files[f2].string() << " are duplicates.\n";
                }
            }
        }

    }

    return 0;
}
