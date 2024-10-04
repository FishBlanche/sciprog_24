#include <stdio.h>
#include <math.h>
#define N 12  
int main() {
    double a = 0;                 
    double b = M_PI / 3;          
    double step = (b - a) / N;        
    double sum = 0.0;              
    double exact_result = log(2);  

    sum = tan(a) + tan(b);

     for (int i = 1; i < N; i++) {
        double x_i = a + i * step;
        sum += 2 * tan(x_i);
    }

     double integral = (b - a) * sum / (2 * N);

    printf("Calculated integral: %.8f\n", integral);
    printf("Expect result (log(2)): %.8f\n", exact_result);
    printf("Difference: %.8f\n", fabs(integral - exact_result));

    return 0;
}
