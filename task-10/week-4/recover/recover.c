#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
/**
 * Common Data Types
 *
 * The data types in this section are essentially aliases for C/C++
 * primitive data types.
 *
 * Adapted from http://msdn.microsoft.com/en-us/library/cc230309.aspx.
 * See http://en.wikipedia.org/wiki/Stdint.h for more on stdint.h.
 */
typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./recover [file]\n");
        return 1;
    }

    char *infile = argv[1];
    // Open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 2;
    }

    BYTE buffer[512];
    int count = 0;
    FILE *img_pointer = NULL;
    char filename[8];
    // Repeat until end of card:
    while (fread(&buffer, 512, 1, inptr) == 1)
    {
        // If start of a new JPEG (0xff 0xd8 0xff 0xe*):
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // If not first JPEG, close previous
            if (!(count == 0))
            {
                fclose(img_pointer);
            }
            // Initialise file
            sprintf(filename, "%03i.jpg", count);
            img_pointer = fopen(filename, "w");
            count++;
        }
        // If JPEG has been found, write to file
        if (!(count == 0))
        {
            fwrite(&buffer, 512, 1, img_pointer);
        }
    }
    fclose(inptr);
    fclose(img_pointer);
    return 0;
}