cmake_minimum_required(VERSION 3.18.2)

set(CMAKE_C_STANDARD 11)

# encode-parity decode-parity
add_executable(encode encode-parity.c)
target_compile_options(encode PRIVATE -Wpedantic -Wall -Wextra)

add_executable(decode decode-parity.c)
target_compile_options(decode PRIVATE -Wpedantic -Wall -Wextra)

# encode-checksum decode-checksum
add_executable(encode-checksum encode-checksum.c)
target_compile_options(encode-checksum PRIVATE -Wpedantic -Wall -Wextra)

add_executable(decode-checksum decode-checksum.c)
target_compile_options(decode-checksum PRIVATE -Wpedantic -Wall -Wextra)

# encode-crc32 decode-crc32
add_executable(encode-crc32 encode-crc32.c)
target_compile_options(encode-crc32 PRIVATE -Wpedantic -Wall -Wextra)

add_executable(decode-crc32 decode-crc32.c)
target_compile_options(decode-crc32 PRIVATE -Wpedantic -Wall -Wextra)
