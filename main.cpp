#include <iostream>
#include <getopt.h>

int main(int argc, char* argv[]) {

    int opt;

    while ((opt = getopt(argc, argv, "hedf")) != -1){

        switch (opt)
        {
            case 'h':
                printf("help command\n");
                break;
            case 'e':
                printf("encrypt\n");
                break;
            case 'd':
                printf("decrypt\n");
                break;
            case 'f':
                printf("file path param\n");
                break;
            case 1:
                printf("no arguments\n");
                break;
        }
    }

    return 0;
}
