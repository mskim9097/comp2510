// lab4.c
// A01424659

#include <stdio.h>
#include <stdlib.h>

void encrypt_text(char *inputFileName, char *outputFileName, int shift)
{
    int ch;

    FILE *in = fopen(inputFileName, "r");
    if (in == NULL) 
    {
        return;
    }

    FILE *out = fopen(outputFileName, "w");
    if (out == NULL)
    {
        fclose(in);
        return;
    }

    // implement area
    while ((ch = fgetc(in)) != -1) //read 1 char
    {
        // for a to z, move 3 position
        if (ch >= 'a' && ch <= 'z')
        {
            ch = 'a' + ((ch - 'a' + shift) % 26);
        } // for A to Z, move 3 position
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = 'A' + ((ch - 'A' + shift) % 26);
        }
        // write encrypted char
        fputc(ch, out);
    }

    //file close
    fclose(in);
    fclose(out);
}

int main(int argc, char **argv)
{
    if(argc != 4)
    {
        return 1;
    }
    char *inputFileName  = argv[1];
    char *outputFileName = argv[2]; 
    int shift = atoi(argv[3]);

    encrypt_text(inputFileName, outputFileName, shift);

    return 0;
}