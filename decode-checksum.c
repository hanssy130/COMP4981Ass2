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

    
    char *parity_message = malloc(sizeof(char) * (strlen(str)+1) );
    char *next_message = malloc(sizeof(char) * (strlen(str)+1) );
    char *building_checksum = malloc(sizeof(char) * (strlen(str)+1) );
    
    for (int i = 0; i < 9; i++) {
    	building_checksum[i] = str[i];
    }
    
    for (size_t j = 0; j < strlen(str)/9; j++) {
        strncpy(parity_message, str+(j*9), (j+1)*9);
        strncpy(next_message, str+((j+1)*9), (j+2)*9);
        parity_message[9] = '\0';
        
        if (j == strlen(str)/9 - 1) {	
        	// printf("cheksum: ^%s^ || paritymsg: ^%s^", building_checksum, parity_message);
		if (strcmp(building_checksum, parity_message) != 0) {
			perror("Checksum input invalid");
		}
        } else {
		bit_to_char_printer(parity_message);
        	
		for (int i = 0; i < 9; i++) {
		        	if (strlen(next_message) <= 9) {
				break;
		}
			// printf("%c %c\n", building_checksum[i], next_message[i]);
			if (odd) {
				if (building_checksum[i] == next_message[i]) {
					building_checksum[i] = '1';
				} else {
					building_checksum[i] = '0';
				}
			} else {
				if (building_checksum[i] == next_message[i]) {
					building_checksum[i] = '0';
				} else {
					building_checksum[i] = '1';
				}
			}
		}
		// printf("buildingchecksum: %s || next msg: %s\n", building_checksum, next_message);
        }
    }
    
    printf("\n");
    free(str);
    return 0;
}
