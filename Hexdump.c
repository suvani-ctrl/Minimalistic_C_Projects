#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>


#define MAX_BUFF_SIZE 1024*500

typedef size_t usize;
typedef uint8_t u8;
typedef uint32_t u32;

void hexdump(char *buffer, usize file_size)
{
  
}

usize file_open_and_read(char *filepath, char *buffer, usize size)
{

    printf("%s\n", filepath);
    if (access(filepath,F_OK) == 0)
    {
        printf("File exists");
    }
    else
    {
        fprintf(stderr,"(+)File doesnt exists!!");
        exit(1);
    }

    FILE *f = fopen(filepath, "r");
    if(f == NULL)
    {
        fprintf(stderr,"(+) COULD NOT OPEN FILE!");
        exit(1);
    }
    else{
        //becus we cant access file more than allcated!

        usize file_size;
        fseek(f,0L, SEEK_END);
        file_size = ftell(f);
        fseek(f,0L,SEEK_SET);
        printf("%zu\n", file_size);
        if(file_size <= 0)
        {
            fprintf(stderr,"[+] Could not open file '%s'", filepath);
            exit(1);
        }
        else if(file_size > size)

        {
            fprintf(stderr,"(+) file size is bigger than allowed!")
            exit(1);
        }

        //READING THE FILES IN MEMORY 
        fread(buffer, sizeof(char), file_size,f)
        {
            fclose(f);
        }
        return file_size;

    }
    return 0;
}



int main(int argc, char **argv)
{
   if(argc != 2)
   {
    fprintf(stderr, "Usage: %s <file>\n", argv[0]);
    exit(1);
   }

   char *filepath = argv[1];
   char buffer[MAX_BUFF_SIZE] = {0};

   usize file_size = file_open_and_read(filepath, buffer, MAX_BUFF_SIZE);

    return 0;
}
