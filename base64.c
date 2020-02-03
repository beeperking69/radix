#include <stddef.h> // size_t
#include <stdint.h> // uint32_t

#define BASE64_PADDING '='

// ------------------------------------------------------------
// ENCODE
// ------------------------------------------------------------
static const unsigned char base64_encode_table[64] =
{
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z', '0', '1', '2', '3',
    '4', '5', '6', '7', '8', '9', '+', '/'
};

size_t encode_length_base64(size_t len)
{
    return ((len + 2) / 3) * 4;
}

char* encode_base64(char* lhv, char* data, size_t len_in)
{
    size_t i = 0;
    size_t j = 0;
    size_t len_out = encode_length_base64(len_in);
    uint32_t a, b, c, d;
    while (i < len_in)
    {
        a = b = c = 0;
        if (i < len_in) a = (uint8_t)(data[i++]);
        if (i < len_in) b = (uint8_t)(data[i++]);
        if (i < len_in) c = (uint8_t)(data[i++]);
        d = (a << 16) + (b << 8) + c;

        if (j < len_out)
            lhv[j++] = base64_encode_table[(d >> 18) & 63];
        if (j < len_out)
            lhv[j++] = base64_encode_table[(d >> 12) & 63];
        if (j < len_out)
            lhv[j++] = base64_encode_table[(d >> 6) & 63];
        if (j < len_out)
            lhv[j++] = base64_encode_table[d & 63];
    }

    size_t p = len_in % 3;
    if (p >= 1) lhv[len_out - 1] = BASE64_PADDING;
    if (p == 1) lhv[len_out - 2] = BASE64_PADDING;

    return lhv;
}

// ------------------------------------------------------------
// DECODE
// ------------------------------------------------------------
static const unsigned char base64_decode_table[123] =
{
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x3F,
    0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B,
    0x3C, 0x3D, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
    0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E,
    0x0F, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16,
    0x17, 0x18, 0x19, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20,
    0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
    0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30,
    0x31, 0x32, 0x33
};

size_t decode_length_base64(size_t len)
{
    return ((len / 4) * 3) + 2;
}

char* decode_base64(char* lhv, char* data, size_t len_in)
{
    size_t len_out = decode_length_base64(len_in);
    if (data[len_in - 1] == BASE64_PADDING) len_out--;
    if (data[len_in - 2] == BASE64_PADDING) len_out--;

    size_t i = 0;
    size_t j = 0;
    uint32_t a, b, c, d, e;
    while (i < len_in)
    {
        a = b = c = d = 0;
        if (i < len_in)
            a = base64_decode_table[(uint8_t)(data[i++])];
        if (i < len_in)
            b = base64_decode_table[(uint8_t)(data[i++])];
        if (i < len_in)
            c = base64_decode_table[(uint8_t)(data[i++])];
        if (i < len_in)
            d = base64_decode_table[(uint8_t)(data[i++])];
        e = (a << 18) + (b << 12) + (c << 6) + d;

        if (j < len_out)
            lhv[j++] = (e >> 16) & 0xFF;
        if (j < len_out)
            lhv[j++] = (e >> 8) & 0xFF;
        if (j < len_out)
            lhv[j++] = e & 0xFF;
    }

    return lhv;
}
