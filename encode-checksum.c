#include <stdio.h>
#include "bit_masking.h"

int main(int argc, const char* argv[]) {
    char *str = malloc(sizeof(char) * (strlen(argv[2])+1) );
    int odd = get_opt(argv[1]);
    char result[10];

    if (argc < 2)
        perror("please specify --parity <input>");
    if (argv[2] == 0) { // read from stdin
        str = read_from_stdin();
    } else if (strstr(argv[2], ".")) {
        char* filename = malloc(sizeof(char) * (strlen(argv[2])+1) );
        strcpy(filename, argv[2]);
        str = read_from_file(filename);
        free(filename);
    } else { // read from command line
        if (!str) {
            perror("Failed malloc");
            exit(EXIT_FAILURE);
        }
        strcpy(str, argv[2]);
    }

    char list[strlen(str)][NUM_BITS];
    for (size_t i = 0; i < strlen(str); i++) {
        char * printable_bits = display(str[i], odd, true);
        strcpy(list[i], printable_bits);
        free(printable_bits);
    }
    checksum(list, result, strlen(str), odd);
    free(str);
    return 0;
}


