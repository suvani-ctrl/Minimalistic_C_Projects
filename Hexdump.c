#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>

#define MAX_BUFF_SIZE 1024 * 1 //500KB

typedef size_t usize;
typedef uint8_t u8;
typedef uint32_t u32;


//function to check the file's existence

usize file_open_and_read(char *filepath, char *buffer, usize size)
{
    

//function to check the file's existence
if (access(filepath, F_OK) != 0)
{
    fprintf(stderr, "[+] THE FILE DOES NOT EXIST!\n", filepath);
    exit(1);
}

}

void hexdump(char *buffer, usize file_size)
{

}

int main(int argc, char **argv)
{
    printf("%d\n",argc);
    if(argc != 2)
    {
    fprintf(stderr, "Usage is : %s\n", argv[0]);
    exit(1);
    }
    char *filepath = argv[1];
    char buffer[MAX_BUFF_SIZE] = {0};
    
    usize file_size = file_open_and_read(filepath, buffer, MAX_BUFF_SIZE);
    hexdump(buffer,file_size);


    return 0;
}
