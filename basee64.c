/*
Instructions for Base64 Encoding in C

    Check if the input file exists. [] partially done !
    Open the input file in binary read mode.
    Create an output file for Base64-encoded data.
    Set up the Base64 encoding table.
    Read the input file in chunks of 3 bytes.
    Convert each chunk of 3 bytes into 24 bits.
    Split the 24 bits into 4 groups of 6 bits.
    Map each 6-bit group to a corresponding Base64 character.
    Handle padding (=) for incomplete chunks.
    Write the Base64-encoded data to the output file.
    Close both the input and output files.
*/
#include <stdio.h>
#include <stdlib.h>

int file_existence(const char *filename)
{
    FILE *file = fopen(filename, "rb");
    if (file)
    {
        fclose(file);
        return 1;
    }
    else
    {
        perror("File does not exist");
        return 0;
    }
}

int main()
{
    FILE *file;
    char buffer[3];
    size_t bytes_read;
    char filename[100];

    printf("Enter the filename: ");
    scanf("%s", filename);

    if (file_existence(filename))
    {
        file = fopen(filename, "rb");
        
        if (file)
        {
            while ((bytes_read = fread(buffer, 1, 3, file)) > 0)
            {
     
                for (size_t i = 0; i < bytes_read; i++)
                {
                    unsigned char byte = buffer[i];
                    for (int j = 7; j >= 0; j--)
                    {
                        printf("%d", (byte >> j) & 1); //each bit (0 or 1)
                    }
                    printf(" "); // Space between each byte's binary representation
                }
                printf("\n"); // New line after each chunk of 3 bytes
            }

            fclose(file);
        }
        else
        {
            printf("Error opening the file!\n");
        }
    }
    else
    {
        printf("File does not exist or can't be opened!\n");
    }

    return 0;
}


