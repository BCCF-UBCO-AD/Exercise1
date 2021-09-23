#include <iostream>
#include <filesystem>
#include <getopt.h>
#include <vector>
#include "common.h"
#include "encrypt-decrypt.h"
#include "files.h"

int main(int argc, char *argv[]) {

    int opt;
    const char *directory;
    std::vector<fs::path> files;

    while (true) { //getopt creates a data-structure that can be looped through from the argv array to process the parameters and their arguments

        int option_index = 0;
        static struct option long_options[] =
                {
                        {"help",     no_argument, NULL,  'h' },
                        {"encrypt",  no_argument, NULL,  'e' },
                        {"decrypt",  no_argument, NULL,  'd' },
                        {NULL,      0,           NULL,  0  }
                };
        opt = getopt_long(argc, argv, "he:d:", long_options, &option_index);

        if(opt == -1)
            break;

        switch (opt) {
            case 'h':
                printf("help command\n");    //placeholder
                break;
            case 'e':
                directory = optarg;
                getFiles(directory, files);
                for (fs::path &i: files) {
                    encrypt(i);
                    std::cout << "Encrypted " << i.string() << "\n";
                }
                break;
            case 'd':
                directory = optarg;
                getFiles(directory, files);
                for (fs::path &i: files) {
                    decrypt(i);
                    std::cout << "Decrypted " << i.string() << "\n";
                }
                break;
            case 1:
                printf("no arguments\n");    //default non-argument case
                break;
        }
    }

    return 0;
}