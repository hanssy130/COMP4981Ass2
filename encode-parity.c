#include <stdio.h>
#include "bit_masking.h"

int main(int argc, const char* argv[]) {
    char *str;
    bool odd = get_opt(argv[1]);
    if (argc < 2) {
        perror("please specify --parity <input>");
        exit(EXIT_FAILURE);
    }
    if (argv[2] == 0) { // read from stdin
        str = read_from_stdin();
    } else {
        str = malloc(sizeof(char) * (strlen(argv[2]) + 1));
        if (strstr(argv[2], ".")) {
            char *filename = malloc(sizeof(char) * (strlen(argv[2]) + 1));
            strcpy(filename, argv[2]);
            str = read_from_file(filename);
            free(filename);
        } else { // read from command line
            str = malloc(sizeof(char) * (strlen(argv[2]) + 1));
            if (!str) {
                perror("Failed malloc");
                exit(EXIT_FAILURE);
            }
            strcpy(str, argv[2]);
        }
    }

    for (size_t j = 0; j < strlen(str); j++) {
        char * printable_bits = display(str[j], odd, true);
        printf("%s", printable_bits);
        free(printable_bits);
    }
    printf("\n");
    free(str);
    return 0;
}