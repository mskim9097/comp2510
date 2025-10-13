#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Update this with your A number
char a_num[] = "01424659";

void zoomArray(char **arr, float n, int *rows, int *cols)
{
    // WRITE YOUR CODE 
    if(n <= 0)
    {
        return;
    }

    int newRows = (int)(*rows * n);
    int newCols = (int)(*cols * n);

    if(newRows == 0 || newCols == 0)
    {
        return;
    }

    char **zoomed = malloc(newRows * sizeof(char *));
    if (!zoomed) {
        return;
    }

    for (int i = 0; i < newRows; i++) 
    {
        zoomed[i] = malloc(newCols * sizeof(char));
        if (!zoomed[i]) 
        {
            for (int k = 0; k < i; k++) 
            {
                free(zoomed[k]);
            }
            free(zoomed);
            return;
        }
    }

    for (int i = 0; i < newRows; i++) 
    {
        for (int j = 0; j < newCols; j++) 
        {
            int origRow = (int)(i / n);
            int origCol = (int)(j / n);

            if (origRow >= *rows) 
            {
                origRow = *rows - 1;
            }
            if (origCol >= *cols) 
            {
                origCol = *cols - 1;
            }
            zoomed[i][j] = arr[origRow][origCol];
        }
    }

    FILE *out = fopen("output.txt", "w");
    if (out == NULL) 
    {
        for (int i = 0; i < newRows; i++) 
        {
            free(zoomed[i]);
        }
        free(zoomed);
        return;
    }

    for (int i = 0; i < newRows; i++) 
    {
        for (int j = 0; j < newCols; j++) 
        {
            fprintf(out, "%c", zoomed[i][j]);
        }
        if (i < newRows - 1) 
        {
            fprintf(out, "\n");
        }
    }

    fclose(out);

    for (int i = 0; i < newRows; i++) 
    {
        free(zoomed[i]);
    }
    free(zoomed);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <input_file> <output_file\n", argv[0]);
        return 1;
    }

    char *inputFileName = argv[1];
    int dimensions = 0;
    char **arr = NULL;
    int rows = 0, cols = 0;
    float zoomFactor = 0;
    
    // Read the input array from the specified file
    FILE *file = fopen(inputFileName, "r");
    if (file == NULL)
    {
        perror("Error opening input file");
        return 1;
    }

    // Read the row value
    fscanf(file, "%d", &rows);
    // Read the column value
    fscanf(file, "%d", &cols);
    // Read the zoom factor
    fscanf(file, "%f", &zoomFactor);

    // Allocate memory for the 2D array
    arr = (char **)malloc(rows * sizeof(char *));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    for (int i = 0; i < rows; i++)
    {
        arr[i] = (char *)malloc(cols * sizeof(char));
        if (arr[i] == NULL)
        {
            printf("Memory allocation failed.\n");
            return 1;
        }
    }

    // Read the elements of the array until 'E' is encountered
    char inputChar;
    int i = 0, j = 0;
    while ((inputChar = fgetc(file)) != 'E')
    {
        if (inputChar >= '0' && inputChar <= '9' && i < rows && j < cols)
        {
            arr[i][j++] = inputChar;
            if (j == cols)
            {
                j = 0;
                i++;
            }
        }
    }

    fclose(file);
    printf("A%s\n", a_num);

    // Output the input array
    printf("Input Array:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Call the zoomArray function
    zoomArray(arr, zoomFactor, &rows, &cols);

    // Free the memory allocated for the 2D array
    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
