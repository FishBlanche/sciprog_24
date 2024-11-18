#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to compute factorial
double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int max_order = 15; // Evaluate up to 15th order
    double x = 1.0;     // x = 1
    double true_e = exp(1.0); // True value of e

    // Loop through polynomial orders from 1 to max_order
    for (int order = 1; order <= max_order; order++) {
        // Dynamically allocate memory for storing terms
        double *terms = (double *)malloc(order * sizeof(double));
        if (terms == NULL) {
            printf("Memory allocation failed.\n");
            return 1;
        }

        // Calculate terms and sum them
        double estimate = 0.0;
        for (int i = 0; i < order; i++) {
            terms[i] = pow(x, i) / factorial(i); // ith term
            estimate += terms[i];              // Add to the estimate
        }

        // Print results
        printf("Order %2d: f(x) = %.10f, Error = %.10e\n", order, estimate, fabs(true_e - estimate));

        // Free allocated memory
        free(terms);
    }

    return 0;
}
