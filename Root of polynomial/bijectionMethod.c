#include <stdio.h>
#include <math.h>

// Function to calculate the value of the equation
float fun(float x) {
    return (2 * x * x * x) - (3 * x) - 5; // Example equation
}

// Function to implement the bisection method
float bijection(float a, float b, float tolerance) {
   
    //if a and b on the same side of the x-axis, return -1
    if(fun(a) * fun(b) >= 0){
        printf("Guess different values for a and b\n");
        return -1;
    }

    float c; // Variable to store the midpoint
    while (fabs(a-b) >= tolerance){
        /* code */
        c = (a+b)/2;

        // Check if c is the root
        if(fun(c) == 0.0) {
            break; // Root found
        }

        if(fun(a)*fun(c) < 0 )
            b = c;
        else    
            a = c;
    
    }
    
    return c; // Return the approximate root
}

int main() {
    int itr = 0, maxmitr = 10;
    float a = 1.0, b = 2.0, tolerance = 1e-6;

    float root = bijection(a, b, tolerance);

    if (root != -1) {
        printf("The root is approximately: %.6f\n", root);
    }

    return 0;
}