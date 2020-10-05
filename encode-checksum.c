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
    } else { // read from command line
        if (!str) {
            perror("Failed malloc");
            exit(EXIT_FAILURE);
        }
        strcpy(str, argv[2]);
    }

    char list[strlen(str)][NUM_BITS];
    for (size_t i = 0; i < strlen(str); i++) {
        strcpy(list[i], display(str[i], odd));
    }
    checksum(list, result, strlen(str), odd);
    free(str);
    return 0;
}


