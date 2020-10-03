cmake_minimum_required(VERSION 3.18.2)
project(COMP4981Ass2 C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic")

include_directories(.)

add_library(bit_masking bit_masking.c)
target_compile_options(bit_masking PRIVATE -Wpedantic -Wall -Wextra)

# encode-parity decode-parity
add_executable(encode-parity encode-parity.c)
target_link_libraries(encode-parity bit_masking)
target_compile_options(encode-parity PRIVATE -Wpedantic -Wall -Wextra)

#add_executable(decode-parity decode-parity.c)
#target_compile_options(decode-parity PRIVATE -Wpedantic -Wall -Wextra)

# encode-checksum decode-checksum
#add_executable(encode-checksum encode-checksum.c)
#target_compile_options(encode-checksum PRIVATE -Wpedantic -Wall -Wextra)

#add_executable(decode-checksum decode-checksum.c)
#target_compile_options(decode-checksum PRIVATE -Wpedantic -Wall -Wextra)

# encode-crc32 decode-crc32
#add_executable(encode-crc32 encode-crc32.c)
#target_compile_options(encode-crc32 PRIVATE -Wpedantic -Wall -Wextra)

#add_executable(decode-crc32 decode-crc32.c)
#target_compile_options(decode-crc32 PRIVATE -Wpedantic -Wall -Wextra)
