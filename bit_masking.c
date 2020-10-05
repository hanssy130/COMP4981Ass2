//
// Created by billy on 2020-10-04.
//

#include "bit_masking.h"

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
    /* ODD PARITY*/
    if (parity) {
        /* EVEN 1s */
        if (counter % 2 == 0) {
            printable[8] = '1';
            /* ODD 1s*/
        } else {
            printable[8] = '0';
        }
        /* EVEN PARITY*/
    } else {
        /* EVEN 1s */
        if (counter % 2 == 0) { // even
            printable[8] = '0';
            /* ODD 1s*/
        } else {
            printable[8] = '1';
        }
    }
    printable[9] = '\0';
}

 void checksum(char list[][NUM_BITS], char result[NUM_BITS], size_t len, bool odd) {
    strcpy(result, list[0]);
    for (size_t j = 1; j < len; j++) {
        for (size_t z = 0; z < NUM_BITS - 1; z++) {
            if (odd) {
                if (result[z] == list[j][z]){
                    result[z] = '1';
                } else
                {
                    result[z] = '0';
                }
            } else {
                if (result[z] == list[j][z]){
                    result[z] = '0';
                } else
                {
                    result[z] = '1';
                }
            }
        }
        result[9]='\0';
    }
    for (size_t y = 0; y < len; y++)
        printf("%s", list[y]);
    printf("%s\n", result);
}

 char* display(int8_t val, bool parity)
{
    bool bits[8];
    char* printable_bits = malloc(10*sizeof(char));

    to_binary(val, bits);
    to_printable_binary(bits, printable_bits, parity);
    return printable_bits;
}

 int test_case(char* result, char* answer) {
    if (strcmp(result, answer) == 0)
        return 1;
    return 0;
}