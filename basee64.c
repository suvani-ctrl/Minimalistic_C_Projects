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
int main() {
    FILE *file;
    unsigned char buffer[1];  // Buffer to store each byte read from the file
    int bytes_read;
    int bit_count = 0;  // To count the bits and insert space after every 6 bits
    int i;
    
    // Open the file for reading in binary mode
    printf("Enter the filename: ");
    char filename[100];
    scanf("%s", filename);
    file = fopen(filename, "rb");

    if (file) {
        while ((bytes_read = fread(buffer, 1, 1, file)) > 0) {
            unsigned char byte = buffer[0];

            for (int j = 7; j >= 0; j--) {
       
                printf("%d", (byte >> j) & 1);

                bit_count++;

                if (bit_count == 6) {
                    printf(" ");  
                    bit_count = 0;  
                }
            }
        }

        if (bit_count > 0 && bit_count < 6) {
            printf(byte);

            int required_bits = 6 - bit_count;
            for(i=0; i<required_bits; i++)
            {   
                printf("0");
                
            }      
        }

        fclose(file);  
    } else {
        printf("Could not open file.\n");
    }

    return 0;
}
