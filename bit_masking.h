//
// Created by Billy on 2020-10-04.
//

#ifndef COMP4981ASS2_BIT_MASKING_H
#define COMP4981ASS2_BIT_MASKING_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define CRC32_POLY 0x04C11DB7

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

/**
 * Read from stdin
 * ./(program) [flag <depend>]
 * @return char * as user input
 */
char *read_from_stdin();
/**
 * Read from file
 * ./(program) [flag <depend>] file
 * @param filename FILE *
 * @return char * as input
 */
char *read_from_file(char* filename);
/**
 * Gets flag with strcmp()
 * @param argv arguments
 * @return integer 1 for odd, 0 for even
 */
int get_opt(const char argv[]);

/**
 * Extracted from bit-masking with little modifications
 * to display and to_printable_binary_w_parity functions
 * by D'Arcy
 */
char *display(int8_t val, bool parity, bool have_parity);
void to_binary(int8_t val, bool value[8]);
bool get_bit_value(int8_t val, uint8_t mask);
void to_printable_binary_w_parity(bool bits[8], char printable[NUM_BITS], bool parity);

/** ENCODE-CHECKSUM */
/**
 * Converts to printable bits without parity flag
 * @param bits bool array of bit-masked values
 * @param printable char array of size 9 (8-bit)
 */
void to_printable_binary(bool bits[8], char printable[9]);

/**
 * Checks parity vertically of all encoded 8-bit-parity strings
 * @param list 2d array of strings
 * @param result char array of size 10
 * @param len size_t, size of encoded message
 * @param odd bool, 1 for odd, 0 for even
 */
void encode_checksum(char list[][NUM_BITS], char result[NUM_BITS], size_t len, bool odd);

/** ENCODE-CRC32 */
/**
 * Checks crc32 of original message without parity flag
 * @param str char* as message
 * @return 32-bit decimal value to be later converted to binary
 */
uint32_t encode_crc32(char* str);

/** TESTING */
/**
 * Uses to test different cases agreed among set O
 * @param result obtained from program
 * @param answer obtained from spreadsheet
 * @return 1 for success, 0 for fail
 */
int test_case(char *result, char *answer);

#endif //COMP4981ASS2_BIT_MASKING_H
