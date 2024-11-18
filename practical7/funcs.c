#include <stdio.h>
#include <stdlib.h>

// Function to allocate an array of integers
int* allocatearray(int size) {
    if (size <= 0) {
        printf("Invalid size. Must be greater than 0.\n");
        return NULL;
    }
    int *array = (int *)malloc(size * sizeof(int));
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit program if memory allocation fails
    }
    return array;
}

// Function to fill an array with ones
void fillwithones(int *array, int size) {
    if (array == NULL || size <= 0) {
        printf("Invalid array or size.\n");
        return;
    }
    for (int i = 0; i < size; i++) {
        array[i] = 1;
    }
}

// Function to print the elements of an array
void printarray(int *array, int size) {
    if (array == NULL || size <= 0) {
        printf("Invalid array or size.\n");
        return;
    }
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Function to free allocated memory
void freearray(int *array) {
    if (array != NULL) {
        free(array);
        printf("Memory freed.\n");
    }
}

int main() {
    int size;

    // Ask the user for array size
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Step 1: Allocate array
    int *array = allocatearray(size);

    // Step 2: Fill the array with ones
    fillwithones(array, size);

    // Step 3: Print the array
    printarray(array, size);

    // Step 4: Free the allocated memory
    freearray(array);

    return 0;
}
