#include <stdio.h>
#include "bit_masking.h"

void parity_check(char * parity_message, bool odd, int index);
void bit_to_char_printer(char * parity_message);

void decode_parity(char * val, bool odd_parity) {
    char *parity_message = malloc(sizeof(char) * (strlen(val)+1) );
    
    for (size_t j = 0; j < strlen(val)/9; j++) {
        strncpy(parity_message, val+(j*9), (j+1)*9);
        parity_message[9] = '\0';
       
        parity_check(parity_message, odd_parity, j);       	
        
        bit_to_char_printer(parity_message);
    }
}

void parity_check(char * parity_message, bool odd, int index) {
	int count = 0;
	
	for(size_t i = 0; i < strlen(parity_message); i++) {
		if (parity_message[i] == '1') {
			count++;
		}
	}
	
	if (count % 2 == 0 && odd) {
		printf("\n--Bad parity at block %d--\n", index);
	} 
	if (count % 2 == 1 && !odd) {
		printf("\n--Bad parity at block %d--\n", index);
	}
}

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
    
    decode_parity(str, odd);
    
    printf("\n");
    free(str);
    return 0;
}
