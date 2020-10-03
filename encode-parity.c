#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

#define MASK_00000001 0x01
#define MASK_00000010 0x02
#define MASK_00000100 0x04
#define MASK_00001000 0x08
#define MASK_00010000 0x10
#define MASK_00100000 0x20
#define MASK_01000000 0x40
#define MASK_10000000 0x80
#define LINESIZE 1024


 void display(int8_t val);
 void to_binary(int8_t val, bool value[8]);
 bool get_bit_value(int8_t val, uint8_t mask);
 void to_printable_binary(bool bits[8], char printable[9]);

int main(int argc, const char* argv[]) {
    char str[LINESIZE];
    int parity = 0;
    if (strcmp(argv[1], "--even") == 0) {
        parity = 1;
    }
    if (argv[2] == 0) {
        printf("Input: ");
        fgets(str, LINESIZE, stdin); 
    } else {
        strcpy(argv[2], str);
    }

    for (int i = 0; i !='\0'; i++)
        display(str[1]);
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

void to_printable_binary(bool bits[8], char printable[9])
{
    for(size_t i = 0; i < 8; i++)
    {
        if(bits[i])
        {
            printable[i] = '1';
        }
        else
        {
            printable[i] = '0';
        }
    }
    
    printable[8] = '\0';
}

void display(int8_t val)
{
    bool bits[8];
    char printable_bits[9];
    
    to_binary(val, bits);
    to_printable_binary(bits, printable_bits);
    printf("char: %c\n", val);
    // printf("hex: %x\n", val);
    // printf("HEX: %X\n", val);
    // printf("decimal: %d\n", val);
    // printf("octal: %o\n", val);
    printf("%s ", printable_bits);
}
