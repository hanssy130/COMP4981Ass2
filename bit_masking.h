#ifndef bit_masking
#define bit_masking

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

static void display(int8_t val);
static void to_binary(int8_t val, bool value[8]);
static bool get_bit_value(int8_t val, uint8_t mask);
static void to_printable_binary(bool bits[8], char printable[9]);

#endif