#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_BUF_SIZE 1024 *1 //500 kilo byte

typedef size_t usize;
typedef uint8_t u8;
typedef uint32_t u32;

//MAIN FUNCTUON 

void hexdump(char *buffer, usize file_size)
{
    return ;
}
usize file_open_and_read(char *filepath, char *buffer, usize size)
{
    return 0;
}

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        fprintf(stderr,"Usage : %s <file>\n", argv[0]);
        exit(1);
    }



    char *filepath = argv[1];
    char buffer[MAX_BUFF_SIZE] = {0};//space allocated on stack

    usize file_size = file_open_and_read(filepath, buffer, MAX_BUF_SIZE)



}
