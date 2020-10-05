//
// Created by billy on 2020-10-04.
//

#ifndef COMP4981ASS2_BIT_MASKING_H
#define COMP4981ASS2_BIT_MASKING_H

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
#define NUM_BITS 10

char *read_from_stdin();
char *read_from_file(char* filename);
int get_opt(const char argv[]);

char *display(int8_t val, bool parity, bool have_parity);
void to_binary(int8_t val, bool value[8]);
bool get_bit_value(int8_t val, uint8_t mask);
void to_printable_binary_w_parity(bool bits[8], char printable[NUM_BITS], bool parity);

char **getlist(char printable[NUM_BITS], size_t len);

/** ENCODE-CHECKSUM */
void to_printable_binary(bool bits[8], char printable[10]);
void checksum(char list[][NUM_BITS], char result[NUM_BITS], size_t len, bool odd);

/** ENCODE-CRC32 */
void crc32(char *message);

/** TESTING */
int test_case(char *result, char *answer);

#endif //COMP4981ASS2_BIT_MASKING_H
