#include <stdio.h>
#include <math.h>

// Function to calculate f(x) = x^3 - 2x - 3
float f(float x) {
    return x * x * x - 2 * x - 3;
}

// Function to calculate derivative f'(x) = 3x^2 - 2
float df(float x) {
    return 3 * x * x - 2;
}

int main() {
    float x0, tolerance;
    int maxIterations, iteration = 0;

    // Initial guess
    printf("Enter the initial guess: ");
    scanf("%f", &x0);

    // Tolerance level
    printf("Enter the tolerance: ");
    scanf("%f", &tolerance);

    // Maximum number of iterations
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &maxIterations);

    float x1;

    // Newton-Raphson iteration
    do {
        if (df(x0) == 0.0) {
            printf("Mathematical error: Derivative is zero.\n");
            return -1;
        }

        x1 = x0 - f(x0) / df(x0); // Newton-Raphson formula

        printf("Iteration %d: x = %.6f\n", iteration + 1, x1);

        if (fabs(x1 - x0) < tolerance) {
            printf("The root is approximately: %.6f\n", x1);
            return 0;
        }

        x0 = x1;
        iteration++;
    } while (iteration < maxIterations);

    printf("The method did not converge within the maximum number of iterations.\n");
    return 0;
}