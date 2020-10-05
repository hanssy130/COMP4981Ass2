#include <stdio.h>
#include "bit_masking.h"

int main(int argc, const char* argv[]) {
    char *str = malloc(sizeof(char) * (strlen(argv[2])+1) );;
    bool odd = get_opt(argv[1]);

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

    for (size_t j = 0; j < strlen(str); j++) {
        printf("%s",display(str[j], odd));
    }
    printf("\n");
    free(str);
    return 0;
}