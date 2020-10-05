#include <stdio.h>
#include "bit_masking.h"

int main(int argc, const char* argv[]) {
    char *str = malloc(sizeof(char) * (strlen(argv[1])+1) );
    char *message = malloc(sizeof(char) * (strlen(argv[1])+1) );

    if (argc < 2)
        perror("please specify <input>");
    if (argv[1] == 0) { // read from stdin
        str = read_from_stdin();
    } else if (strstr(argv[1], ".")) {
        char* filename = malloc(sizeof(char) * (strlen(argv[1])+1) );
        strcpy(filename, argv[1]);
        str = read_from_file(filename);
        free(filename);
    } else { // read from command line
        if (!str) {
            perror("Failed malloc");
            exit(EXIT_FAILURE);
        }
        strcpy(str, argv[1]);
    }
    /** PROGRAM */
    for (size_t i = 0; i < strlen(str); i++) {
        message = strcat(message, display(str[i], 1, false));
    }
    printf("%s", message);
    crc32(message);
    free(str);
    return 0;
}