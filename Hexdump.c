#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>


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
    //checking if the file exists

    if(access(filepath, F_OK)!= 0)
    {
        fprintf(stderr,"[ERROR]: File '%s' does not exist !\n");
        exit(1);
    }

    //IF THE FILE EXISTS  LETS OPEN THE FILE
    
    

    File *f = fopen(filepath, "r"); //opening the file in Read  method
    if(f == NULL)
    {
        fprintf(stderr,"[ERROR]: Could not opem file '%s' !\n", filepath);
        exit(1);
    }
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
