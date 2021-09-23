#include <iostream>
#include <filesystem>
#include <getopt.h>
#include <vector>
#include "common.h"
#include "encrypt-decrypt.h"
#include "files.h"

int main(int argc, char *argv[]) {

    int opt;
    int eord = -1;
    char directory;
    std::vector<fs::path> files;

    while ((opt = getopt(argc, argv, "hedf")) !=-1) { //getopt creates a data-structure that can be looped through from the argv array to process the parameters and their arguments

        /*int option_index = 0;
        static struct option long_options[] =
                {
                        {"help",     no_argument, NULL,  'h' },
                        {"encrypt",  no_argument, NULL,  'e' },
                        {"decrypt",  no_argument, NULL,  'd' },
                        {"file",     required_argument,  NULL, 'f' },
                        {NULL,      0,           NULL,  0  }
                };
        opt = getopt_long(argc, argv, "hedf", long_options, &option_index);

        if(opt == -1)
            break;
*/
        switch (opt) {
            case 'h':
                printf("help command\n");    //placeholder
                break;
            case 'e':

                if(eord == -1) {
                    eord = 0;
                }else{
                    std::cout << "Choose either encrypt or decrypt but not both" << std::endl;
                }
                break;
            case 'd':

                if(eord == -1) {
                    eord = 1;
                }else{
                    std::cout << "Choose either encrypt or decrypt but not both" << std::endl;
                }
                break;
            case 'f':
                directory = *optarg;
                break;
            case 1:
                printf("no arguments\n");    //default non-argument case
                break;
        }
    }

    if(eord == 0){
        getFiles(&directory, files);
        for (fs::path &i: files) {
            encrypt(i);
            std::cout << "Encrypted " << i.string() << "\n";
        }
    }else if(eord == 1){
        getFiles(&directory, files);
        for (fs::path &i: files) {
            decrypt(i);
            std::cout << "Encrypted " << i.string() << "\n";
        }
    }else
    return 0;
}