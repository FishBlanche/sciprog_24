#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100
#include "magic_square.h"

int getlines(char filename[MAX_FILE_NAME]);
// Function to read the matrix from a file
int **readMatrix(const char *filename, int *size) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    fscanf(file, "%d", size);
    if (*size <= 0) {
        fclose(file);
        return NULL;
    }

    int **matrix = (int **)malloc(*size * sizeof(int *));
    for (int i = 0; i < *size; i++) {
        matrix[i] = (int *)malloc(*size * sizeof(int));
        for (int j = 0; j < *size; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    fclose(file);
    return matrix;
}

// Function to free allocated memory for the matrix
void freeMatrix(int **matrix, int size) {
    for (int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}
int main(){  

    //define our file variable
    FILE *f;  
    char filename[MAX_FILE_NAME];
    printf("Enter file name: ");
    scanf("%s", filename);
    
    // ##! n function which gets the number of lines
        int n = getlines(filename);

        int **matrix = readMatrix(filename, &n);
        if (!matrix) {
            fprintf(stderr, "Failed to read matrix from %s\n", files[f]);
            return 0;
        }

        if (isMagicSquare(matrix, n)) {
            printf("The matrix in %s is a magic square.\n", filename);
        } else {
            printf("The matrix in %s is NOT a magic square.\n", filename);
        }

        freeMatrix(matrix, n);

    return 0;
}  

//##!

int getlines(char filename[MAX_FILE_NAME]) {
    FILE *fp;
    fp = fopen(filename, "r");
    
    int ch_read;
    int count = 0;

    while( (ch_read = fgetc(fp)) != EOF)
    {
        if (ch_read == '\n'){
            count++;
        }
    }

    printf("No. lines, %d\n", count);
    fclose(fp); 
    return count;
}
