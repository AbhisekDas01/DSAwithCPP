#include <iostream>
#include <vector>
using namespace std;

// Function to calculate the nth Fibonacci number using memoization (Top-Down approach)
int fibonacciSeries(int n, vector<int> &dpArray)
{
    // Base case: if n is 0 or 1, return n (0th Fibonacci is 0, 1st Fibonacci is 1)
    if (n == 1 || n == 0)
    {
        return n;
    }

    // Check if the Fibonacci value for n is already computed and stored in dpArray
    if (dpArray[n] != -1)
    {
        return dpArray[n];
    }

    // Recursive step: calculate Fibonacci(n) as the sum of Fibonacci(n-1) and Fibonacci(n-2)
    // Store the result in dpArray to avoid recalculating it in the future
    dpArray[n] = fibonacciSeries(n - 1, dpArray) + fibonacciSeries(n - 2, dpArray);

    return dpArray[n];
}

// Function to calculate the nth Fibonacci number using Bottom-Up approach (Tabulation)
int fibSeries(int n, vector<int> &dpArray)
{
    // Initialize base cases
    dpArray[0] = 0; // 0th Fibonacci is 0
    dpArray[1] = 1; // 1st Fibonacci is 1

    // Build up the dpArray table to store values up to nth Fibonacci
    for (int i = 2; i <= n; i++)
    {
        dpArray[i] = dpArray[i - 1] + dpArray[i - 2];
    }

    return dpArray[n];
}

int main()
{
    int n;
    cout << "Enter the nth term : ";
    cin >> n;

    // Create a vector to store previously computed Fibonacci values
    // Initialize all values with -1 to indicate uncomputed values
    vector<int> dpArray(n + 1, -1);

    // Calculate the nth Fibonacci number using the Bottom-Up approach
    int ans = fibSeries(n, dpArray);

    // Output the result
    cout << "The " << n << "th Fibonacci number is : " << ans;
    return 0;
}
