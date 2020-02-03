#ifndef __RADIX_BASE64_H__
#define __RADIX_BASE64_H__

#include <stddef.h>

// ------------------------------------------------------------
// ENCODE
// ------------------------------------------------------------
size_t encode_length_base64 (size_t len);
char*  encode_base64        (char* lhv, char* data, size_t len_in);

// ------------------------------------------------------------
// DECODE
// ------------------------------------------------------------
size_t decode_length_base64 (size_t len);
char*  decode_base64        (char* lhv, char* data, size_t len_in);

void print_table();

#endif