#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Task: https://cs50.harvard.edu/x/2021/labs/4/

// Structs
typedef uint8_t BYTE;
typedef int16_t DOULBE_BYTE;

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    BYTE header[HEADER_SIZE];
    fread(&header, sizeof(header), 1, input);
    fwrite(&header, sizeof(header), 1, output);

    // TODO: Read samples from input file and write updated data to output file
    DOULBE_BYTE buffer;
    while (fread(&buffer, sizeof(DOULBE_BYTE), 1, input))
    {
        buffer = buffer * factor;
        fwrite(&buffer, sizeof(DOULBE_BYTE), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
