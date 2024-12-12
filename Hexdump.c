#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#define MAX_BUFF_SIZE 1024 * 500

typedef size_t usize;
typedef uint8_t u8;
typedef uint32_t u32;

void hexdump(char *buffer, usize size) {
    usize i, j;

    for (i = 0; i < size; i += 16) { 
     
        for (j = i; j < i + 16 && j < size; j++) {
            printf("%02x ", (unsigned char)buffer[j]);
        }

   
        printf(" | ");
        for (j = i; j < i + 16 && j < size; j++) {
            printf("%c", (buffer[j] >= 32 && buffer[j] <= 126) ? buffer[j] : '.');
        }

        printf("\n");
    }
}

usize file_open_and_read(char *filepath, char *buffer, usize size) {
    printf("Opening file: %s\n", filepath);
    
    if (access(filepath, F_OK) != 0) {
        fprintf(stderr, "(+) File doesn't exist!\n");
        exit(1);
    } else {
        printf("File exists.\n");
    }

    FILE *f = fopen(filepath, "r");
    if (f == NULL) {
        fprintf(stderr, "(+) Could not open file!\n");
        exit(1);
    } else {
        usize file_size;

        fseek(f, 0L, SEEK_END);
        file_size = ftell(f);
        fseek(f, 0L, SEEK_SET);
        printf("File size: %zu bytes\n", file_size);

        if (file_size <= 0) {
            fprintf(stderr, "[+] Could not read file '%s'. It may be empty.\n", filepath);
            fclose(f);
            exit(1);
        } else if (file_size > size) {
            fprintf(stderr, "(+) File size exceeds the buffer limit!\n");
            fclose(f);
            exit(1);
        }

        size_t bytes_read = fread(buffer, sizeof(char), file_size, f);
        if (bytes_read != file_size) {
            fprintf(stderr, "(+) Error reading file!\n");
            fclose(f);
            exit(1);
        }
        
        fclose(f);
        return file_size;
    }

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    char *filepath = argv[1];
    char buffer[MAX_BUFF_SIZE] = {0};

   
    usize file_size = file_open_and_read(filepath, buffer, MAX_BUFF_SIZE);

    hexdump(buffer, file_size);

    return 0;
}
