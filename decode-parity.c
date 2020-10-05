#include <stdio.h>
#include "bit_masking.h"

int main(int argc, const char* argv[]) {
    char *str = malloc(sizeof(char) * (strlen(argv[1])+1) );

    if (argc < 2)
        perror("please specify <input>");
    if (argv[2] == 0) { // read from stdin
        str = read_from_stdin();
    } /*else if (strstr(argv[2], ".")) {
        char* filename = malloc(sizeof(char) * (strlen(argv[2])+1) );
        strcpy(filename, argv[2]);
        str = read_from_file(filename);
        free(filename);
    }*/ else { // read from command line
        if (!str) {
            perror("Failed malloc");
            exit(EXIT_FAILURE);
        }
        strcpy(str, argv[2]);
    }
    /** PROGRAM */
    decode(str);

    free(str);
    return 0;
}