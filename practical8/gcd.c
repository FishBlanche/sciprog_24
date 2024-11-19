#include <stdio.h>

// Iterative implementation of GCD
int gcd_iterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Recursive implementation of GCD
int gcd_recursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd_recursive(b, a % b);
}

int main() {
    int num1, num2;

    // Input two integers
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Call the iterative GCD function
    int result_iterative = gcd_iterative(num1, num2);
    printf("GCD (Iterative) of %d and %d: %d\n", num1, num2, result_iterative);

    // Call the recursive GCD function
    int result_recursive = gcd_recursive(num1, num2);
    printf("GCD (Recursive) of %d and %d: %d\n", num1, num2, result_recursive);

    return 0;
}
