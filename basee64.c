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
#include <math.h>

int binary_to_decimal( File *outputFile)
{

   
    File = fopen("binary.txt","rb");
    if(!outputFile)
        perror("+File doesnt exists!");
    while ((bytes_read_binary = fread(buffer,1,1,file))>0)
    {

    }
    
    
}


int main() {
    FILE *file, *outputFile;
    unsigned char buffer[1];  
    int bytes_read;
    int bit_count = 0; 
    int i;
  
    printf("Enter the filename: ");
    char filename[100];
    scanf("%s", filename);
   
    file = fopen(filename, "rb");
    if (file) {
    
        outputFile = fopen("binary.txt", "w");
        if (!outputFile) {
            printf("Could not open output file.\n");
            fclose(file);
            return 1;
        }


        while ((bytes_read = fread(buffer, 1, 1, file)) > 0) {
            unsigned char byte = buffer[0];

            for (int j = 7; j >= 0; j--) {
             
                fprintf(outputFile, "%d", (byte >> j) & 1); // Print each bit

                bit_count++;

                if (bit_count == 6) {
              
                    fprintf(outputFile, " ");  
                    bit_count = 0;  
                }
            }
        }

    
        if (bit_count > 0 && bit_count < 6) {
            int required_bits = 6 - bit_count;
            for(i = 0; i < required_bits; i++) {
                fprintf(outputFile, "0");  
            }
        }

  
        fclose(file);  
        fclose(outputFile);  
        printf("Output written to binary.txt\n");
    } else {
        printf("Could not open file.\n");
    }



    return 0;
}
