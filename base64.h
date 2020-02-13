#ifndef __RADIX_BASE64_H__
#define __RADIX_BASE64_H__

#include <stddef.h> // size_t

// ------------------------------------------------------------
// ENCODE
// ------------------------------------------------------------
size_t base64_encode_length (const size_t len);
char*  base64_encode        (char* lhv, const char* data, const size_t len_in);

// ------------------------------------------------------------
// DECODE
// ------------------------------------------------------------
size_t base64_decode_length (const size_t len);
char*  base64_decode        (char* lhv, const char* data, const size_t len_in);

#endif