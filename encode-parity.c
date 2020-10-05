#include <stdio.h>
#include "bit_masking.h"

int main(int argc, const char* argv[]) {
    char *str;
    bool odd = false;

    if (argc < 2)
        perror("please specify --parity <input>");

    if (strcmp(argv[1], "--odd") == 0){
        odd = true;
    }
    if (strcmp(argv[1], "--odd") != 0 && strcmp(argv[1], "--even") != 0) {
        perror("please specify --parity");
    }
    if (argv[2] == 0) { // read from stdin
        str = read_from_stdin();
    } else { // read from command line
        str = malloc(sizeof(char) * (strlen(argv[2])+1) );
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
    //printf("%d", test_case("011100001011101011010010101001101111010100011011100111010000111011100100010110100011001100010001110010011111001101100010100110011010010001101001010011010011010111010110001010100110", "011100001011101011010010101001101111010100011011100111010000111011100100010110100011001100010001110010011111001101100010100110011010010001101001010011010011010111010110001010100110"));
    free(str);
    return 0;
}