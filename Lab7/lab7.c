#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    if (in == NULL)
    {
        return 1;
    }

    FILE *out = fopen(argv[2], "w");
    if (out == NULL)
    {
        fclose(in);
        return 1;
    }

    char line[256];
    int bitWidth = 0;
    long long operand1 = 0;
    long long operand2 = 0;
    int isOperand = 0;

    fscanf(in, "%d", &bitWidth);

    int ch;
    while ((ch = fgetc(in)) != '\n' && ch != EOF) { /* discard */ }

    if (fgets(line, sizeof(line), in) != NULL)
    {
        if (line[0] != 'E')
        {
            operand1 = atoll(line);
            isOperand = 1;

            if (fgets(line, sizeof(line), in) != NULL)
            {
                if (line[0] != 'E')
                {
                    operand2 = atoll(line);
                }
            }
        }
    }

    long long min = -(1LL << (bitWidth - 1));
    long long max =  (1LL << (bitWidth - 1)) - 1;

    if (isOperand == 0)
    {
        fprintf(out, "min: %lld\t0x%016llx\n", min, (unsigned long long)min);
        fprintf(out, "max: %lld\t0x%016llx\n", max, (unsigned long long)max);
    }
    else
    {
        long long result = operand1 * operand2;

        // n-bit MASK. i.e. m = 0xFF
        long long m = 0;
        for (int i = 0; i < bitWidth; i++) 
        {
            m = (m << 1) | 1LL;
            // 0...00000001 | 0...00000001
            // 0...00000010 | 0...00000001 = 0...000000011
            // ...
            // 0...11111110 | 0...00000001 = 0...111111111
        }
        long long low  = result & m; // all to 0, except right bitwidth-bits
        // 0...000000FF & 0...00000003D = 0...0000003D
        // 0...000000FF & F...FFFFFFF4D = 0...0000004D
      
        long long sbit = (low >> (bitWidth - 1)) & 1LL; // sbit == 1: negative, 0: positive

        // ~m:   0xFFFFFFFFFFFFFF00
        // (-1): 0xFFFFFFFFFFFFFFFF
        // 0:    0x0000000000000000
        long long ext  = low | ((~m) & (-(long long)sbit));

        if (ext != result) {
            if((result >> 63) & 1LL) result = min;
            else                     result = max;
        }

        fprintf(out, "%lld\n", result);
    }

    fclose(in);
    fclose(out);
    return 0;
}