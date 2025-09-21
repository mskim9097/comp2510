#include <stdio.h>
#include <stdlib.h>

// update this with your A number
char a_num[] = "01424659";

void rotateArray(int arr[10][10], int n, int rows, int cols) {

int rotated[10][10] = {0};

    // 90 == -270 180 == -180 270 == -90
    n = ((n % 360) + 360) % 360;  

    if (n == 90) { // 90 or -270
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rotated[j][rows - 1 - i] = arr[i][j];
            }
        }
    } else if (n == 180) { // 180 or -180
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rotated[rows - 1 - i][cols - 1 - j] = arr[i][j];
            }
        }
    } else if (n == 270) { // 270 or -90
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rotated[cols - 1 - j][i] = arr[i][j];
            }
        }
    } else { // 0 or 360
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                rotated[i][j] = arr[i][j];
            }
        }
    }

    // 3. rotated → arr
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = rotated[i][j];
        }
    }

    // Do NOT write any code below
    // Output the rotated array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
	    if(arr[i][j] == 0)
	      printf(" ");
	    else
	      printf("%d", arr[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file> <input_angle_degrees>\n", argv[0]);
        return 1;
    }

    char *inputFileName = argv[1];
    int rotationAngle = 0;
    int dimensions = 0;
    int arr[10][10] = {0};  // Initialize the array with zeros
    int rows = 0, cols = 0;
    char inputChar;

    // Read the input array from the specified file
    FILE *file = fopen(inputFileName, "r");
    if (file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    // Read the first line for angle of rotation and second line for array dimensions
    fscanf(file, "%d", &rotationAngle);
    fscanf(file, "%d", &dimensions);
    // Read the input array character by character
    int counter = 0; //To skip first two lines in the file
    while (rows < 10 && (inputChar = fgetc(file)) != 'E') {
        if (inputChar == '\n'){counter++;}
        if (inputChar == '\n' && counter>=2) {
            rows++;
            cols = 0;
        } else if (cols < 10 && inputChar >= '0' && inputChar <= '9') {
            arr[rows][cols++] = inputChar - '0';
        }
    }

    fclose(file);
    printf("A%s\n", a_num);
    // Actual dimensions of the input array
    rows = cols = dimensions;

    printf("Input array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
	    if(arr[i][j] == 0)
	      printf(" ");
	    else
	      printf("%d", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nRotated array (%d degrees):\n", rotationAngle);
    rotateArray(arr, rotationAngle, rows, cols);

    return 0;
}
