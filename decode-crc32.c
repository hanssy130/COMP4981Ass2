#include <stdio.h>
#include "bit_masking.h"

void bit_to_char_printer(char * parity_message) {
    	char bit_message[10];
	unsigned char character;
    	
    	strncpy(bit_message, parity_message, 8);
    	bit_message[8] = '\0';
	character = strtol(bit_message, 0, 2);
	printf("%c", character);
}

int main(int argc, const char* argv[]) {
    char *str;

    if (argc < 2) {
        str = read_from_stdin();
    } else {
        if (strstr(argv[1], ".")) {
            char *filename = malloc(sizeof(char) * (strlen(argv[1]) + 1));
            strcpy(filename, argv[1]);
            str = read_from_file(filename);
            free(filename);
        } else { // read from command line
            str = malloc(sizeof(char) * (strlen(argv[1]) + 1));
            if (!str) {
                perror("Failed malloc");
                exit(EXIT_FAILURE);
            }
            strcpy(str, argv[1]);
        }
    }
    
    char *str_without_remainder = malloc(sizeof(char) * (strlen(str)+1) );
    strncpy(str_without_remainder, str, strlen(str) - 32);
    char *current_message = malloc(sizeof(char) * (strlen(str)+1) );
    for (size_t j = 0; j < strlen(str_without_remainder)/8; j++) {
    	strncpy(current_message, str_without_remainder+(j*8), 8);
    	bit_to_char_printer(current_message);
    }

    putchar('\n');
    return 0;
}
