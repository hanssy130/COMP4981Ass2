#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 1024

void display(char* bits, bool parity);
void to_char(char* bits, char* decoded);
char * read_from_stdin();

int main(int argc, const  char* argv[]) {
    char *bits;
    bool odd = false;

    if (argc < 2)
        perror("please specify --parity <input>");

    if (strcmp(argv[1], "--odd") == 0){
        odd = true;
    }
    if (strcmp(argv[1], "--odd") != 0 && strcmp(argv[1], "--even") != 0)
        perror("please specify --parity");

    if (argv[2] == 0) { // read from stdin
        bits = read_from_stdin();
    } else { // read from command line
        bits = malloc(sizeof(char) * (strlen(argv[2])+1) );
        if (!bits) { 
            perror("Failed malloc");
            exit(EXIT_FAILURE);
        }   
        strcpy(bits, argv[2]);
    }

    for (size_t j = 0; j < strlen(bits); j++) {
        display(bits, odd);
    }
    free(bits);

    return 0;
}

char * read_from_stdin() {
    char *bits = malloc(LINESIZE *sizeof(char));
    if (!bits) { 
        perror("Failed malloc");
        exit(EXIT_FAILURE);
    }  
    fgets(bits, LINESIZE, stdin); 
    if (bits[strlen(bits)-1] == '\n') // case where input file does not have \n character
        bits[strlen(bits)-1]='\0';
    return bits;
}

void to_char(char* bits, char* decoded) {
    printf("in to_char\n");
    char* nine_bits[9];
    size_t counter = 0;
    // for (size_t i = 0; i < strlen(decoded); i++) {
    //     printf("in loop %ld", i);
    //     for (size_t j = 0; j < 9;j++) {
    //         strcpy(nine_bits[j], bits[counter]);
    //         printf("%c", bits[counter]);
    //         counter++;
    //     }
    //     char c = strtol(*nine_bits, 0, 2);
    //     printf("%c", c);
    //     decoded[i] = c;
    // }
    // decoded[strlen(decoded)+1]='\0';
}

void display(char* bits, bool parity)
{
    char *decoded;
    to_char(bits, decoded);
    printf("%s", decoded);
    printf("bits: %s\n", bits);
    // printf("hex: %x\n", val);
    // printf("HEX: %X\n", val);
    // printf("decimal: %d\n", val);
    // printf("octal: %o\n", val);
    for (size_t i = 0; i < strlen(decoded); i++)
        printf("char: %c", decoded[i]);
    printf("\n");
}