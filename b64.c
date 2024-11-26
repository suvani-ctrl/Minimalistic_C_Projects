#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Base64 encoding table
const char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


void encode_base64(const unsigned char *input, int length, char *output) {
    int i = 0, j = 0;
    unsigned char a3[3];
    unsigned char a4[4];

    while (length--) {
        a3[i++] = *(input++);
        if (i == 3) {
            a4[0] = (a3[0] & 0xfc) >> 2;
            a4[1] = ((a3[0] & 0x03) << 4) | ((a3[1] & 0xf0) >> 4);
            a4[2] = ((a3[1] & 0x0f) << 2) | ((a3[2] & 0xc0) >> 6);
            a4[3] = a3[2] & 0x3f;

            for (i = 0; i < 4; i++) {
                output[j++] = base64_table[a4[i]];
            }

            i = 0;
        }
    }

    if (i) {
        for (int k = i; k < 3; k++) {
            a3[k] = '\0';
        }

        a4[0] = (a3[0] & 0xfc) >> 2;
        a4[1] = ((a3[0] & 0x03) << 4) | ((a3[1] & 0xf0) >> 4);
        a4[2] = ((a3[1] & 0x0f) << 2) | ((a3[2] & 0xc0) >> 6);
        a4[3] = a3[2] & 0x3f;

        for (int k = 0; k < i + 1; k++) {
            output[j++] = base64_table[a4[k]];
        }

        while (i++ < 3) {
            output[j++] = '=';
        }
    }

    output[j] = '\0';  // Null-terminate the output
}

// Function to decode base64 string
int decode_base64(const char *input, unsigned char *output) {
    int i = 0, j = 0;
    unsigned char a3[3];
    unsigned char a4[4];
    int input_len = strlen(input);
    int output_len = 0;

    while (input_len--) {
        if (*input == '=' || *input == '\n' || *input == '\r') {
            input++;
            continue;
        }

        a4[i++] = *input++;
        if (i == 4) {
            for (i = 0; i < 4; i++) {
                a4[i] = (unsigned char)strchr(base64_table, a4[i]) - base64_table;
            }

            a3[0] = (a4[0] << 2) | ((a4[1] & 0x30) >> 4);
            a3[1] = ((a4[1] & 0xf) << 4) | ((a4[2] & 0x3c) >> 2);
            a3[2] = ((a4[2] & 0x3) << 6) | a4[3];

            for (i = 0; i < 3; i++) {
                output[output_len++] = a3[i];
            }

            i = 0;
        }
    }

    return output_len;
}

int main() {
    const char *text = "Hello, World!";
    char encoded[1024];
    unsigned char decoded[1024];

    printf("Original: %s\n", text);

    // Encode the text
    encode_base64((const unsigned char *)text, strlen(text), encoded);
    printf("Encoded: %s\n", encoded);

    // Decode the base64 string
    int decoded_len = decode_base64(encoded, decoded);
    decoded[decoded_len] = '\0';  // Null-terminate the decoded string
    printf("Decoded: %s\n", decoded);

    return 0;
}
