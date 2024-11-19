#include <stdio.h>
// Checks if a matrix is a magic square.
// A magic square is an n-sided matrix whose sum of values for each
// row, column, main and secondary diagonals equals to n(n^2 + 1)/2.
// The function takes as input a matrix 'square' and its side length 'n'
// and outputs 0 if 'n' is negative or 'square' is NOT a magic square;
// otherwise, outputs a non-zero value
//


int isMagicSquare(int ** square, const int n) {

    // Eliminate the case where 'n' is negative
    if(n < 0) {
        return 0;
    }

    // sum is the sum of every row, column,
    // and the main and secondary diagonals
    int sum = (n * (n*n + 1))/2;

      // Check row sums
    for (int i = 1; i < n; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += matrix[i][j];
        }
        if (rowSum != sum) {
            return false;
        }
    }

    // Check column sums
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < n; i++) {
            colSum += matrix[i][j];
        }
        if (colSum != sum) {
            return false;
        }
    }

    // Check main diagonal
    int diag1Sum = 0;
    for (int i = 0; i < n; i++) {
        diag1Sum += matrix[i][i];
    }
    if (diag1Sum != sum) {
        return false;
    }

    // Check secondary diagonal
    int diag2Sum = 0;
    for (int i = 0; i < n; i++) {
        diag2Sum += matrix[i][n - 1 - i];
    }
    if (diag2Sum != sum) {
        return false;
    }

    return true;
    


     
}

