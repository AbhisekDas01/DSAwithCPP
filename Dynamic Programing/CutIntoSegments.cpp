#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

// Recursive function to solve the maximum segment cuts problem
int MasSegmentRec(vector<int> &arr, int n)
{
    // Base case: If n is 0, no more cuts are needed
    if (n == 0)
    {
        return 0;
    }
    // Base case: If n is negative, this path is invalid
    if (n < 0)
    {
        return INT_MIN;
    }

    int maxi = INT_MIN; // Initialize maximum cuts to the smallest possible integer

    // Iterate over each segment length in arr
    for (int i = 0; i < arr.size(); i++)
    {
        int ans = MasSegmentRec(arr, n - arr[i]); // Recursive call for the remaining length

        // Update maxi if this path is valid and yields a better result
        if (ans != INT_MIN)
        {
            maxi = max(maxi, ans + 1);
        }
    }

    return maxi; // Return the maximum cuts found
}

// Recursive function with memoization to find the maximum number of cuts
int solveDP(vector<int> &arr, int n, vector<int> &dp)
{
    // Base case: If length is exactly 0, no more cuts are needed
    if (n == 0)
    {
        return 0;
    }
    // Base case: If length is negative, this path is invalid
    if (n < 0)
    {
        return INT_MIN;
    }

    // Return the stored result if it exists to avoid redundant computation
    if (dp[n] != -1)
    {
        return dp[n];
    }

    int maxi = INT_MIN; // Initialize maximum cuts as the smallest possible integer

    // Iterate over each segment length in arr
    for (int i = 0; i < arr.size(); i++)
    {
        int ans = solveDP(arr, n - arr[i], dp); // Recursive call with remaining length

        // Update maxi if this path is valid and yields a better result
        if (ans != INT_MIN)
        {
            maxi = max(maxi, ans + 1);
        }
    }

    // Store the result in dp array to avoid recomputation
    dp[n] = maxi;
    return maxi; // Return the maximum cuts found
}

// Tabulation method to solve the maximum segment cuts problem
int solveTabulation(vector<int> &arr, int n)
{
    // Initialize DP array with INT_MIN to represent initially invalid states
    vector<int> dp(n + 1, INT_MIN);

    dp[0] = 0; // Base case: 0 length requires 0 cuts

    // Iterate over each segment length in arr
    for (int i = 0; i < arr.size(); i++)
    {
        // Iterate through each length from 1 to n
        for (int j = 1; j <= n; j++)
        {
            // If current length can accommodate arr[i] and previous length is valid
            if (j - arr[i] >= 0 && dp[j - arr[i]] != INT_MIN)
            {
                dp[j] = max(dp[j], 1 + dp[j - arr[i]]);
            }
        }
    }
    return dp[n]; // Return the maximum cuts found for the full length
}

// Function to initialize segment lengths and invoke the required solution method
int cutSegments(int n, int x, int y, int z)
{
    vector<int> arr = {x, y, z}; // Vector to store segment lengths

    // Uncomment the method you want to test:

    // Recursive approach
    // int ans = MasSegmentRec(arr, n);

    // Memoization approach
    // vector<int> dp(n + 1, -1); // Initialize DP array for memoization
    // int ans = solveDP(arr, n, dp);

    // Tabulation approach
    int ans = solveTabulation(arr, n);

    // If ans is still INT_MIN, no valid cuts were found; return 0
    return (ans == INT_MIN) ? 0 : ans;
}

// Main function to test the code
int main()
{
    int n, x, y, z;
    cout << "Enter the length of the rod: ";
    cin >> n;
    cout << "Enter the three segment lengths: ";
    cin >> x >> y >> z;

    int result = cutSegments(n, x, y, z);
    cout << "The maximum number of segments that can be cut is: " << result << endl;

    return 0;
}
