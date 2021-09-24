#include <iostream>
#include <getopt.h>
#include "common.h"
#include "encrypt-decrypt.h"
#include "files.h"

int main(int argc, char *argv[]) {

    int opt, option_index = 0, eord = -1;
    const char *directory;
    std::vector<fs::path> files;
    static struct option long_options[] =
            {
                    {"help",     no_argument, NULL,  'h' },
                    {"encrypt",  no_argument, NULL,  'e' },
                    {"decrypt",  no_argument, NULL,  'd' },
                    {NULL,      0,    NULL,   0  }
            };


    while (opt != -1) { //getopt creates a data-structure that can be looped through from the argv array to process the parameters and their arguments

        opt = getopt_long(argc, argv, "he:d:", long_options, &option_index);

        switch (opt) {
            case 'h':
                printf("Usage: ex1 [OPTION]...[ARG]..\n"
                       "Used to encrypt and decrypt directories given a root path as the argument. You can only\n"
                       "use on argument at a time encrypt or decrypt\n\n"
                       "options:\n"
                       "-e, --encrypt     | Encrypts files in a given directory and accepts the root path as an argument \n"
                       "-d, --decrypt     | Decrypts encrypted files from this program and accepts the root path as an argument\n"
                       "-h, --help        | Prints help message\n"
                );    //placeholder
                break;
            case 'e':
                if (eord < 0) {
                    directory = optarg;
                    eord = 0;
                }else{
                    eord = 2;
                }
                break;
            case 'd':
                if (eord < 0) {
                directory = optarg;
                eord = 1;
                }else{
                    eord = 2;
                }
                break;
            case 1:
                printf("no arguments\n");    //default non-argument case
                break;
        }
    }

    if(eord == 0){
        getFiles(directory, files);
        for (fs::path &i: files) {
            encrypt(i);
            std::cout << "Encrypted " << i.string() << "\n";
        }
    }else if(eord == 1){
        getFiles(directory, files);
        for (fs::path &i: files) {
            decrypt(i);
            std::cout << "Decrypted " << i.string() << "\n";
        }
    }else if(eord == 2){
        std::cout << "Must choose either encrypt or decrypt" << std::endl;
    }

    return 0;
}
