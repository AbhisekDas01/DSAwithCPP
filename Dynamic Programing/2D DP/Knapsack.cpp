#include <bits/stdc++.h>
using namespace std;

// Recursive solution without memoization
int solve(vector<int> weight, vector<int> value, int n, int index, int capacity)
{
    // Base case: if we reach the last item
    if (index == n - 1)
    {
        // Check if the last item's weight is within the remaining capacity
        if (weight[index] <= capacity)
            return value[index]; // Include the last item's value if it fits
        else
            return 0; // Exclude the last item if it doesn't fit
    }

    int incl = 0;
    // Option to include the current item if it fits within the remaining capacity
    if (weight[index] <= capacity)
    {
        incl = value[index] + solve(weight, value, n, index + 1, capacity - weight[index]);
    }

    // Option to exclude the current item
    int excl = solve(weight, value, n, index + 1, capacity);

    // Return the maximum of including or excluding the current item
    return max(incl, excl);
}

// Recursive solution with memoization
int solveDp(vector<int> weight, vector<int> value, int n, int index, int capacity, vector<vector<int>> &dp)
{
    // Base case: if we reach the last item
    if (index == n - 1)
    {
        // Check if the last item's weight is within the remaining capacity
        if (weight[index] <= capacity)
            return value[index]; // Include the last item's value if it fits
        else
            return 0; // Exclude the last item if it doesn't fit
    }

    // If the value is already computed, return it to avoid redundant calculations
    if (dp[index][capacity] != -1)
        return dp[index][capacity];

    int incl = 0;
    // Option to include the current item if it fits within the remaining capacity
    if (weight[index] <= capacity)
    {
        incl = value[index] + solveDp(weight, value, n, index + 1, capacity - weight[index], dp);
    }

    // Option to exclude the current item
    int excl = solveDp(weight, value, n, index + 1, capacity, dp);

    // Store the maximum of including or excluding the item in the memoization table
    dp[index][capacity] = max(incl, excl);

    // Return the stored result for the current index and capacity
    return dp[index][capacity];
}

// 2D DP approach (tabulation)
int solveTap(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Initialize a 2D DP table with size (n x (maxWeight + 1))
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    // Initialize the first row with values if the first item fits within the current weight capacity
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        dp[0][i] = value[0];
    }

    // Fill the DP table row by row for each item
    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int incl = 0;
            // Option to include the current item if it fits within the current weight capacity
            if (weight[index] <= w)
            {
                incl = value[index] + dp[index - 1][w - weight[index]];
            }

            // Option to exclude the current item
            int excl = dp[index - 1][w];

            // Store the maximum of including or excluding the current item
            dp[index][w] = max(incl, excl);
        }
    }

    // The final answer is in the last cell, representing the maximum value for given capacity
    return dp[n - 1][maxWeight];
}

// Space-optimized 1D DP approach using two arrays
int solveSo(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Initialize two 1D arrays to keep track of previous and current results
    vector<int> prev(maxWeight + 1, 0);
    vector<int> curr(maxWeight + 1, 0);

    // Initialize the first item if it fits within the current weight capacity
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        prev[i] = value[0];
    }

    // Fill the DP array iteratively for each item
    for (int index = 1; index < n; index++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            int incl = 0;
            // Option to include the current item if it fits
            if (weight[index] <= w)
            {
                incl = value[index] + prev[w - weight[index]];
            }

            // Option to exclude the current item
            int excl = prev[w];

            // Store the maximum of including or excluding the item in the current array
            curr[w] = max(incl, excl);
        }
        // Update previous to current for the next iteration
        prev = curr;
    }

    // The answer is in the last element of the previous array for the given capacity
    return prev[maxWeight];
}

// Further space-optimized 1D DP using a single array
int solve(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Initialize a single 1D array for DP
    vector<int> curr(maxWeight + 1, 0);

    // Initialize for the first item if it fits within the capacity
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        curr[i] = value[0];
    }

    // Fill the array from the back for each item
    for (int index = 1; index < n; index++)
    {
        for (int w = maxWeight; w >= 0; w--)
        {
            int incl = 0;
            // Option to include the current item if it fits
            if (weight[index] <= w)
            {
                incl = value[index] + curr[w - weight[index]];
            }

            // Option to exclude the current item
            int excl = curr[w];

            // Update the DP array with the maximum value for this weight
            curr[w] = max(incl, excl);
        }
    }

    // The result is in the last cell of the array for the given maxWeight
    return curr[maxWeight];
}

// Wrapper functions to call each solution method
int knapsackRecursive(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return solve(weight, value, n, 0, maxWeight);
}

int knapsackMemo(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solveDp(weight, value, n, 0, maxWeight, dp);
}

int main()
{
    vector<int> weight = {1, 3, 4, 5};
    vector<int> value = {1, 4, 5, 7};
    int n = weight.size();
    int maxWeight = 7;

    // Test each function and output the maximum value obtainable
    cout << "Maximum value using recursion: " << knapsackRecursive(weight, value, n, maxWeight) << endl;
    cout << "Maximum value using memoized recursion: " << knapsackMemo(weight, value, n, maxWeight) << endl;
    cout << "Maximum value using 2D DP approach: " << solveTap(weight, value, n, maxWeight) << endl;
    cout << "Maximum value using space-optimized 1D DP: " << solveSo(weight, value, n, maxWeight) << endl;
    cout << "Maximum value using single-array optimized DP: " << solve(weight, value, n, maxWeight) << endl;

    return 0;
}
