cmake_minimum_required(VERSION 3.17.3)
project(COMP4981Ass2 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_library(bit STATIC bit_masking.c)
target_compile_options(bit PRIVATE -Wpedantic -Wall -Wextra)

# encode-parity
add_executable(encode-parity encode-parity.c)
target_link_libraries(encode-parity bit)
target_compile_options(encode-parity PRIVATE -Wpedantic -Wall -Wextra)

# decode-parity
add_executable(decode-parity decode-parity.c)
target_link_libraries(decode-parity bit)
target_compile_options(decode-parity PRIVATE -Wpedantic -Wall -Wextra)

# encode-checksum
add_executable(encode-checksum encode-checksum.c)
target_link_libraries(encode-checksum bit)
target_compile_options(encode-checksum PRIVATE -Wpedantic -Wall -Wextra)

# decode-checksum
add_executable(decode-checksum decode-checksum.c)
target_link_libraries(decode-checksum bit)
target_compile_options(decode-checksum PRIVATE -Wpedantic -Wall -Wextra)

# encode-crc32 decode-crc32
add_executable(encode-crc32 encode-crc32.c)
target_link_libraries(encode-crc32 bit)
target_compile_options(encode-crc32 PRIVATE -Wpedantic -Wall -Wextra)

#add_executable(decode-crc32 decode-crc32.c)
#target_compile_options(decode-crc32 PRIVATE -Wpedantic -Wall -Wextra)
