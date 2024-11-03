#include <stdio.h>
#include <math.h>

#define NUM_POINTS 13 // 0, 5, 10, ..., 60 (inclusive)
#define DEG_TO_RAD 0.017453292519943295 // Pi / 180

// Global array to store tan(x) values
double tan_values[NUM_POINTS];

// Function to convert degrees to radians
double degrees_to_radians(int degrees) {
    return degrees * DEG_TO_RAD;
}

// Function to calculate the area under tan(x) curve using the Trapezoidal Rule
double trapezoidal_area(double *values, int num_points, double h) {
    double area = 0.0;
    for (int i = 0; i < num_points - 1; i++) {
        area += (values[i] + values[i + 1]) * h / 2.0;
    }
    return area;
}

int main() {
    // Loop to calculate tan(x) for angles 0, 5, 10, ..., 60 degrees
    for (int i = 0; i < NUM_POINTS; i++) {
        int degrees = i * 5; // Generate angles 0, 5, 10, ..., 60
        double radians = degrees_to_radians(degrees); // Convert to radians
        tan_values[i] = tan(radians); // Compute tan(x) and store in array
        printf("tan(%d degrees) = %f\n", degrees, tan_values[i]);
    }

    // Calculate the area under the curve of tan(x) from 0 to 60 degrees
    double h = degrees_to_radians(5); // Step size in radians (5 degrees)
    double area = trapezoidal_area(tan_values, NUM_POINTS, h);

    printf("\nArea under the curve of tan(x) from 0 to 60 degrees: %f\n", area);

    return 0;
}
