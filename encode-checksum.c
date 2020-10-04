#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MASK_00000001 0x01
#define MASK_00000010 0x02
#define MASK_00000100 0x04
#define MASK_00001000 0x08
#define MASK_00010000 0x10
#define MASK_00100000 0x20
#define MASK_01000000 0x40
#define MASK_10000000 0x80
#define LINESIZE 1024

char* display(int8_t val, bool parity);
void to_binary(int8_t val, bool value[8]);
bool get_bit_value(int8_t val, uint8_t mask);
void to_printable_binary(bool bits[8], char printable[9], bool parity);
char * read_from_stdin();
char** getlist(char printable[10], size_t len);
void checksum(char** list, char result[10], size_t len);

int main(int argc, const char* argv[]) {
    char *str;
    bool odd = false;
    char result[10];

    if (argc < 2)
        perror("please specify --parity <input>");

    if (strcmp(argv[1], "--odd") == 0){
        odd = true;
    }
    if (strcmp(argv[1], "--odd") != 0 && strcmp(argv[1], "--even") != 0)
        perror("please specify --parity");

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
    char** list = malloc(strlen(str) * sizeof(char));
    for (size_t i = 0; i < strlen(str); i++) {
        list[i] = malloc((LINESIZE+1)*sizeof(char));
        strcpy(list[i], display(str[i], odd));
    }
    checksum(list, result, strlen(str));
    free(str);
    free(list);
}

char * read_from_stdin() {
    char *str = malloc(LINESIZE *sizeof(char));
    if (!str) { 
        perror("Failed malloc");
        exit(EXIT_FAILURE);
    }  
    fgets(str, LINESIZE, stdin); 
    if (str[strlen(str)-1] == '\n') // case where input file does not have \n character
        str[strlen(str)-1]='\0';
    return str;
}

void to_binary(int8_t val, bool bits[8]) {
    bits[0] = get_bit_value(val, MASK_10000000);
    bits[1] = get_bit_value(val, MASK_01000000);
    bits[2] = get_bit_value(val, MASK_00100000);
    bits[3] = get_bit_value(val, MASK_00010000);
    bits[4] = get_bit_value(val, MASK_00001000);
    bits[5] = get_bit_value(val, MASK_00000100);
    bits[6] = get_bit_value(val, MASK_00000010);
    bits[7] = get_bit_value(val, MASK_00000001);
}

bool get_bit_value(int8_t val, uint8_t mask)
{
    uint8_t masked;
    bool bit;
    
    masked = val & mask;
    
    if(masked > 0)
    {
        bit = true;
    }
    else
    {
        bit = false;
    }
    
    return bit;
}

void to_printable_binary(bool bits[8], char printable[10], bool parity)
{
    int counter = 0;
    for(size_t i = 0; i < 8; i++)
    {
        if(bits[i])
        {
            printable[i] = '1';
            counter++;
        }
        else
        {
            printable[i] = '0';
        }
    }
     if (parity) { // odd parity
         if (counter % 2 == 0) { // even
             printable[8] = '1';
         } else { // odd
             printable[8] = '0';
         }
     } else { //even parity
         if (counter % 2 == 0) { // even
             printable[8] = '0';   
         } else { // odd
             printable[8] = '1';
         }
     }
    
    printable[9] = '\0';
}

void checksum(char**list, char result[10], size_t len) {
    for (size_t j = 0; j < len; j++) {
        for (size_t z = 0; z < strlen(list[j]); z++) {
            if (list[j][z] == list[j+1][z]) {
                result[z] = '0';
            } else {
                result[z] = '1';
            } 
        }

        for (size_t x = 0; x < 10; x++) {
                list[j+1][x] = result[x];
        }

        if (j == (len-2)) // at last string
            break;

    }
    printf("checksum: %s\n", result);
}

char* display(int8_t val, bool parity)
{
    bool bits[8];
    char* printable_bits = malloc(10*sizeof(char));
    
    to_binary(val, bits);
    to_printable_binary(bits, printable_bits, parity);
    printf("char: %c\n", val);
    // printf("hex: %x\n", val);
    // printf("HEX: %X\n", val);
    // printf("decimal: %d\n", val);
    // printf("octal: %o\n", val);
    printf("binary with parity: %s\n", printable_bits);
    //strcpy(list[count], printable_bits);
    return printable_bits;
}
