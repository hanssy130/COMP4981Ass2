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

void display(int8_t val, bool parity);
void to_binary(int8_t val, bool value[8]);
bool get_bit_value(int8_t val, uint8_t mask);
void to_printable_binary(bool bits[8], char printable[10], bool parity);
char * read_from_stdin();
int test_case(char* result, char* answer);

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
        display(str[j], odd);
    }
    printf("\n");
    //printf("%d", test_case("011100001011101011010010101001101111010100011011100111010000111011100100010110100011001100010001110010011111001101100010100110011010010001101001010011010011010111010110001010100110", "011100001011101011010010101001101111010100011011100111010000111011100100010110100011001100010001110010011111001101100010100110011010010001101001010011010011010111010110001010100110"));
    free(str);
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

void display(int8_t val, bool parity)
{
    bool bits[8];
    char printable_bits[10];
    
    to_binary(val, bits);
    to_printable_binary(bits, printable_bits, parity);
    printf("%s", printable_bits);
}

int test_case(char* result, char* answer) {
    if (strcmp(result, answer) == 0)
        return 1;
    return 0;
}