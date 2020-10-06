#include <stdio.h>
#include "bit_masking.h"

int main(int argc, const char* argv[]) {
    char *str;
    char *message = malloc(sizeof(char) * LINESIZE);
    if (argc < 2) {
        str = read_from_stdin();
    } else if (argc >= 2) {
        str = malloc(sizeof(char) * (strlen(argv[1]) + 1));
        if (strstr(argv[1], ".")) {
            char *filename = malloc(sizeof(char) * (strlen(argv[1]) + 1));
            strcpy(filename, argv[1]);
            str = read_from_file(filename);
            free(filename);
        } else { // read from command line
            if (!str) {
                perror("malloc");
                exit(EXIT_FAILURE);
            }
            strcpy(str, argv[1]);
        }
    }

    /** PROGRAM */
    for (size_t i = 0; i < strlen(str); i++) {
        message = strcat(message, display(str[i], 1, false));
        char* tmp = realloc(message, sizeof(char)*(strlen(message)+LINESIZE));
        if (tmp) {
            message = tmp;
        } else {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
    }
    printf("%s", message); // prepending message
    uint32_t v = encode_crc32(str);

    /** CONVERTING CRC TO BINARY */
    /** https://stackoverflow.com/questions/33577659/converting-decimal-to-32-bit-binary */
   uint32_t mask = 1 << 31;
    for (int i=0; i<8; i++) {
        for (int j=0; j<4; j++) {
            // check current bit, and print
            char c = (v & mask) == 0 ? '0' : '1';
            putchar(c);
            // move down one bit
            mask >>= 1;
        }
        // print a space very 4 bits
    }
    putchar('\n');
    free(str);
    free(message);
    return 0;
}
