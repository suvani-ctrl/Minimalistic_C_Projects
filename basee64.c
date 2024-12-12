#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Base64 Alphabet
const char base64_table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

// Function to get the index of a character in the base64 table
int base64_char_to_index(char c) {
    for (int i = 0; i < 64; i++) {
        if (base64_table[i] == c) {
            return i;
        }
    }
    return -1; // Invalid character
}

// Base64 decoding function
int base64_decode(const char *input, uint8_t *output) {
    int input_length = strlen(input);
    int output_length = (input_length / 4) * 3; // Base64 encoding increases size by 33%
    
    if (input_length % 4 != 0) {
        return -1; // Invalid base64 input length
    }
    
    int j = 0;
    for (int i = 0; i < input_length; i += 4) {
        // Decode each 4-character group
        int index1 = base64_char_to_index(input[i]);
        int index2 = base64_char_to_index(input[i + 1]);
        int index3 = base64_char_to_index(input[i + 2]);
        int index4 = base64_char_to_index(input[i + 3]);
        
        if (index1 == -1 || index2 == -1 || index3 == -1 || index4 == -1) {
            return -1; // Invalid character in base64 input
        }

        // Combine the 4 characters into 3 bytes
        output[j++] = (index1 << 2) | (index2 >> 4);
        if (index3 != 64) { // Skip padding character ('=')
            output[j++] = ((index2 & 0x0F) << 4) | (index3 >> 2);
        }
        if (index4 != 64) { // Skip padding character ('=')
            output[j++] = ((index3 & 0x03) << 6) | index4;
        }
    }
    
    return output_length;
}

int main() {
    // Example Base64 encoded string
    const char *base64_input = "SGVsbG8gd29ybGQh"; // "Hello world!" encoded in Base64
    uint8_t decoded_output[1024];

    int decoded_length =
