#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024 * 1 // 500 kilo byte

typedef size_t usize;
typedef uint8_t u8;
typedef uint32_t u32;

// MAIN FUNCTION
void hexdump(char *buffer, usize file_size)
{
    return;
}

usize file_open_and_read(char *filepath, char *buffer, usize size)
{
    // checking if the file exists
    if (access(filepath, F_OK) != 0)
    {
        fprintf(stderr, "[ERROR]: File '%s' does not exist!\n", filepath);
        exit(1);
    }

    // IF THE FILE EXISTS, LET'S OPEN THE FILE
    FILE *f = fopen(filepath, "r"); // opening the file in Read mode
    if (f == NULL)
    {
        fprintf(stderr, "[ERROR]: Could not open file '%s'!\n", filepath);
        exit(1);
    }

    // processing file size not too big not too small
    // if file size small, load it into program's memory

    usize file_size;
    fseek(f, 0L, SEEK_END);
    file_size = ftell(f);
    fseek(f, 0L, SEEK_SET);

    printf("%zu\n", file_size);

    if (file_size <= 0)
    {
        fprintf(stderr, "[ERROR]: File has '%zu' <= 0 bytes!\n", file_size);
        exit(1);
    }
    else if (file_size > size)
    {
        fprintf(stderr, "[ERROR]: File size (%zu) is too big, max size allowed is %zu\n", file_size, size);
        exit(1);
    }

    fread(buffer, 1, file_size, f); // Load the file content into the buffer
    fclose(f);

    return file_size;
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    char *filepath = argv[1];
    char buffer[MAX_BUF_SIZE] = {0}; // space allocated on stack

    usize file_size = file_open_and_read(filepath, buffer, MAX_BUF_SIZE);

    hexdump(buffer, file_size);

    return 0;
}
