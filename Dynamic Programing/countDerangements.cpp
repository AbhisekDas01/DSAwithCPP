/* Problem statement
A Derangement is a permutation of ‘N’ elements, such that no element appears in its original
position. For example, an instance of derangement of {0, 1, 2, 3} is {2, 3, 1, 0}, because 2
present at index 0 is not at its initial position which is 2 and similarly for other elements
of the sequence.

Given a number ‘N’, find the total number of derangements possible of a set of 'N’ elements.
*/

#include <iostream>
#include <vector>
using namespace std;

// Recursive approach to count derangements (without memoization)
long long int countDerangements(int n)
{

    // Base case: if there's only one element, no derangements possible
    if (n == 1)
    {
        return 0;
    }

    // Base case: if there are two elements, only one derangement (swap them)
    if (n == 2)
    {
        return 1;
    }

    // Recursive formula: D(n) = (n - 1) * (D(n - 1) + D(n - 2))
    // This calculates derangements by breaking it down into smaller subproblems
    return (n - 1) * (countDerangements(n - 2) + countDerangements(n - 1));
}

// Recursive approach with memoization to avoid recalculating subproblems
long long int solveDp(int n, vector<long long int> &dp)
{

    // Base cases for 1 and 2 elements
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }

    // If the result is already computed, return it to save time
    if (dp[n] != -1)
    {
        return dp[n];
    }

    // Use recursive relation and store result in dp array for memoization
    dp[n] = (n - 1) * (solveDp(n - 2, dp) + solveDp(n - 1, dp));

    return dp[n];
}

// Tabulation method: Dynamic programming approach using an iterative solution
long long int solveTab(int n)
{

    // Initialize dp array of size n+1 for storing intermediate derangement counts
    vector<long long int> dp(n + 1);

    // Base cases
    dp[1] = 0; // No derangement possible for 1 element
    dp[2] = 1; // Only 1 derangement for 2 elements (swap)

    // Iteratively fill dp array using recurrence relation
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (i - 1) * (dp[i - 2] + dp[i - 1]);
    }

    return dp[n];
}

// Space-optimized approach to reduce space complexity to O(1)
long long int solveSo(int n)
{

    // Initialize variables to store results for the previous two values in the sequence
    long long int prev1 = 1; // Equivalent to dp[2]
    long long int prev2 = 0; // Equivalent to dp[1]

    // Calculate derangements iteratively while updating only two variables
    for (int i = 3; i <= n; i++)
    {
        long long int first = prev1;
        long long int second = prev2;

        long long int sum = first + second;

        // Current derangement count based on the recurrence relation
        long long int curr = (i - 1) * sum;

        // Update previous values for next iteration
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1; // Result for dp[n]
}

int main()
{
    int n;

    // Prompt user for input
    cout << "Enter the number of elements (n): ";
    cin >> n;

    // Uncomment one of the methods below to calculate derangements

    // Method 1: Using basic recursion (inefficient for large n)
    // long long int result = countDerangements(n);

    // Method 2: Using recursion + memoization
    vector<long long int> dp(n + 1, -1);
    // int result = solveDp(n, dp);

    // Method 3: Using tabulation (bottom-up dynamic programming)
    // int result = solveTab(n);

    // Method 4: Using space optimization
    int result = solveSo(n);

    // Output the result
    cout << "The number of derangements for " << n << " elements is: " << result << endl;

    return 0;
}
