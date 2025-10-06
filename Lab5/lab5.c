#include <stdio.h>
#include <stdlib.h>

//A method that puts star
void put_pixel(char *canvas, int width, int height, int minX, int maxY, int x, int y)
{
    int cx = x - minX;
    int cy = maxY - y;
    if (cx >= 0 && cx < width && cy >= 0 && cy < height) {
        *(canvas + cy * width + cx) = '*';
    }
}

// A method that connects previous coordinate and current coordinate.
void draw_line(char *canvas, int width, int height, int minX, int maxY,
               int prevX, int prevY, int currX, int currY)
{
    int dx = (currX > prevX) ? 1 : (currX < prevX ? -1 : 0);
    int dy = (currY > prevY) ? 1 : (currY < prevY ? -1 : 0);

    int x = prevX, y = prevY;
    put_pixel(canvas, width, height, minX, maxY, x, y);

    while (x != currX || y != currY) {
        x += dx;
        y += dy;
        put_pixel(canvas, width, height, minX, maxY, x, y);
    }
}

void drawShape(char *inputFileName, char *outputFileName)
{
    FILE *in = fopen(inputFileName, "r");
    if (in == NULL) 
    {
        FILE *out = fopen(outputFileName, "w");
        if (out != NULL) {
            fprintf(out, "Error\n");
            fclose(out);
        }
        return;
    }

    FILE *out = fopen(outputFileName, "w");
    if (out == NULL)
    {
        fclose(in);
        return;
    }

    // implement area
    // Step 1: find min/max
    int x, y;
    int minX, maxX, minY, maxY;
    int first = 1;
    int count = 0;

    while (1)
    {
        char c;
        if (fscanf(in, "%d,%d", &x, &y) == 2)
        {
            if (first)
            {
                minX = maxX = x;
                minY = maxY = y;
                first = 0;
            }
            else 
            {
                if (x < minX) minX = x;
                if (x > maxX) maxX = x;
                if (y < minY) minY = y;
                if (y > maxY) maxY = y;
            }
            count++;
        }
        else if (fscanf(in, " %c", &c) == 1 && c == 'E')
        {
            break;
        }
        else
        {
            fprintf(out, "Error\n");
            fclose(in);
            fclose(out);
            return;
        }
    }
    
    // Step 2: allocate exact memory
    if (count < 2) 
    {
        fprintf(out, "Error\n");
        fclose(in);
        fclose(out);
        return;
    }

    int width = maxX - minX + 1;
    int height = maxY - minY + 1;
    char *canvas = malloc(width * height);
    if (!canvas)
    {
        fprintf(out, "Error\n");
        fclose(in);
        fclose(out);
        return;
    }

    // initialize canvas
    for (int i = 0; i < width * height; i++) {
        *(canvas + i) = ' ';
    }

    // Step 3: rewind file and read again for drawing
    rewind(in);

    int prevX = 0, prevY = 0;
    int havePrev = 0;
    char c;


    // Draw line
    while (1) 
    {
        int currX, currY;

        if (fscanf(in, "%d,%d", &currX, &currY) == 2) 
        {
            if (!havePrev) 
            {
                prevX = currX; prevY = currY;
                havePrev = 1;
            } 
            else 
            {
                draw_line(canvas, width, height, minX, maxY, prevX, prevY, currX, currY);
                prevX = currX; prevY = currY;
            }
        }
        else if (fscanf(in, " %c", &c) == 1 && c == 'E') 
        {
            break;
        }
        else 
        {
            fprintf(out, "Error\n");
            free(canvas);
            fclose(in);
            fclose(out);
            return;
        }
    }

    // fill inside
    for (int row = 0; row < height; ++row) 
    {
        int first = -1, last = -1;
        for (int col = 0; col < width; ++col) 
        {
            if (*(canvas + row * width + col) == '*') 
            { 
                first = col; 
                break;
            }
        }
        for (int col = width - 1; col >= 0; --col) 
        {
            if (*(canvas + row * width + col) == '*') 
            { 
                last = col; 
                break; 
            }
        }
        if (first >= 0 && last > first) 
        {
            for (int col = first + 1; col < last; ++col) 
            {
                *(canvas + row * width + col) = '*';
            }
        }
    }

    /* Step 4: write canvas to output (trim empty bottom rows & right spaces) */
    int lastRow = -1;
    // find last row that has at least one '*'
    for (int row = 0; row < height; ++row) 
    {
        for (int col = 0; col < width; ++col) 
        {
            if (*(canvas + row * width + col) == '*') 
            { 
                lastRow = row; 
                break; 
            }
        }
    }
    if (lastRow >= 0) 
    {
        for (int row = 0; row <= lastRow; ++row) 
        {
            int lastCol = -1;
            for (int col = 0; col < width; ++col) 
            {
                if (*(canvas + row * width + col) == '*') lastCol = col;
            }
            if (lastCol < 0) continue; // skip fully empty rows

            for (int col = 0; col <= lastCol; ++col) 
            {
                fputc(*(canvas + row * width + col), out);
            }
            // no trailing newline on the very last printed row
            if (row < lastRow) fputc('\n', out);
        }
    } 
    else 
    {
        // shape somehow empty — write nothing
    }

    //file close
    free(canvas);
    fclose(in);
    fclose(out);
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        return 1;
    }

    drawShape(argv[1], argv[2]);

    return 0;
}