#include "test_assert/test_assert.h"

void test_base64_encode();
void test_base64_decode();

TEST_SUITE(
    test_base64_encode,
    test_base64_decode
);

#include "base64.h"
#define OUTPUT_MAX_LENGTH 2048

static const char* const LEVIATHAN_RAW =
    "Man is distinguished, not only by his reason, "
    "but by this singular passion from other animals, "
    "which is a lust of the mind, "
    "that by a perseverance of delight in the continued "
    "and indefatigable generation of knowledge, "
    "exceeds the short vehemence of any carnal pleasure.";

static const char* const LEVIATHAN_B64 =
    "TWFuIGlzIGRpc3Rpbmd1aXNoZWQsIG5vdCBvbmx5IGJ5IGhpcyByZWFzb24sIGJ1dCBieSB0aGlz"
    "IHNpbmd1bGFyIHBhc3Npb24gZnJvbSBvdGhlciBhbmltYWxzLCB3aGljaCBpcyBhIGx1c3Qgb2Yg"
    "dGhlIG1pbmQsIHRoYXQgYnkgYSBwZXJzZXZlcmFuY2Ugb2YgZGVsaWdodCBpbiB0aGUgY29udGlu"
    "dWVkIGFuZCBpbmRlZmF0aWdhYmxlIGdlbmVyYXRpb24gb2Yga25vd2xlZGdlLCBleGNlZWRzIHRo"
    "ZSBzaG9ydCB2ZWhlbWVuY2Ugb2YgYW55IGNhcm5hbCBwbGVhc3VyZS4=";

void test_base64_encode()
{
    // Given
    char actual[OUTPUT_MAX_LENGTH];
    memset(actual, 0, OUTPUT_MAX_LENGTH);

    // When
    base64_encode(actual, LEVIATHAN_RAW, strlen(LEVIATHAN_RAW));

    // Then
    assert_array_equals(LEVIATHAN_B64, actual, sizeof(char), strlen(LEVIATHAN_B64), NULL);
}

void test_base64_decode()
{
    // Given
    char actual[OUTPUT_MAX_LENGTH];
    memset(actual, 0, OUTPUT_MAX_LENGTH);

    // When
    base64_decode(actual, LEVIATHAN_B64, strlen(LEVIATHAN_B64));

    // Then
    assert_array_equals(LEVIATHAN_RAW, actual, sizeof(char), strlen(LEVIATHAN_RAW), NULL);
}