#include <stdio.h>
#include "bit_masking.h"

int main(int argc, const char* argv[]) {
    char *str = malloc(sizeof(char) * (strlen(argv[1])+1) );
    char *message = malloc(sizeof(char) * (strlen(argv[1])+1) );

    if (argc < 2)
        perror("please specify <input>");
    if (argv[1] == 0) { // read from stdin
        str = read_from_stdin();
    } else { // read from command line
        if (!str) {
            perror("Failed malloc");
            exit(EXIT_FAILURE);
        }
        strcpy(str, argv[1]);
    }

    for (size_t i = 0; i < strlen(str); i++) {
        message = strcat(message, display(str[i], 1, false));
    }
    printf("%s", message);
    crc32(message);
    free(str);
    return 0;
}