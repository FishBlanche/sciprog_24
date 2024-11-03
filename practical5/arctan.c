#include <stdio.h>
#include <math.h>

#define MAX_TERMS 1000  // Maximum number of terms for series approximation
#define MAX_RESULTS 181 // Results array size for the range [-0.9, 0.9] with step 0.01

// Part 1: Fibonacci Sequence
void fibonacci_next(int *prev, int *curr) {
    int next = *prev + *curr;
    *prev = *curr;
    *curr = next;
}

void fibonacci_series(int n) {
    int prev = 0, curr = 1;
    printf("Fibonacci series up to term %d:\n", n);
    printf("%d ", prev);

    for (int i = 1; i < n; i++) {
        printf("%d ", curr);
        fibonacci_next(&prev, &curr);
    }
    printf("\n");
}

// Part 2: Hyperbolic Arc Tangent Calculations

// Maclaurin series approximation for arctanh(x)
double artanh1(double x, double delta) {
    double term = x, sum = 0.0;
    int n = 0;

    while (fabs(term) > delta && n < MAX_TERMS) {
        sum += term;
        n++;
        term = pow(x, 2 * n + 1) / (2 * n + 1);
    }
    return sum;
}

// Natural logarithm approximation for arctanh(x)
double artanh2(double x) {
    return 0.5 * (log(1 + x) - log(1 - x));
}

// Comparison function for accuracy
void compare_results(double results1[], double results2[], int count) {
    printf("Comparing artanh1 and artanh2 results (10 significant figures):\n");
    for (int i = 0; i < count; i++) {
        printf("x = %.2f: artanh1 = %.10f, artanh2 = %.10f, difference = %.10f\n",
               -0.9 + i * 0.01, results1[i], results2[i], fabs(results1[i] - results2[i]));
    }
}

int main() {
    // Part 1: Fibonacci sequence
    int n;
    printf("Enter the number of terms for the Fibonacci series: ");
    scanf("%d", &n);
    fibonacci_series(n);

    // Part 2: Inverse Hyperbolic Tangent Calculations
    double delta;
    printf("Enter the precision delta for arctanh Maclaurin series approximation: ");
    scanf("%lf", &delta);

    double results_artanh1[MAX_RESULTS];
    double results_artanh2[MAX_RESULTS];

    // Compute arctanh(x) for x in [-0.9, 0.9] with step 0.01
    for (int i = 0; i < MAX_RESULTS; i++) {
        double x = -0.9 + i * 0.01;
        results_artanh1[i] = artanh1(x, delta);
        results_artanh2[i] = artanh2(x);
    }

    // Compare accuracy of both methods
    compare_results(results_artanh1, results_artanh2, MAX_RESULTS);

    return 0;
}
