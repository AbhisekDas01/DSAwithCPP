#include <bits/stdc++.h>
using namespace std;

// Helper function to recursively find the minimum number of elements
// required to reach the target sum x
int findMin(vector<int> &num, int x)
{
    // Base case: if x is exactly 0, no more elements are needed
    if (x == 0)
    {
        return 0;
    }

    // If x becomes negative, it means this combination is invalid
    if (x < 0)
    {
        return INT_MAX;
    }

    int mini = INT_MAX;

    // Check each element in num to find the minimum combination
    for (int i = 0; i < num.size(); i++)
    {
        // Recursive call with reduced target
        int ans = findMin(num, x - num[i]);

        // If a valid combination was found, update mini with the minimum number of elements
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }

    return mini;
}

// DP approach: Recursion with memoization to store already computed results
int findMinDp(vector<int> &num, int x, vector<int> &dpArray)
{
    // Base case: if x is exactly 0, no more elements are needed
    if (x == 0)
    {
        return 0;
    }

    // If x becomes negative, it means this combination is invalid
    if (x < 0)
    {
        return INT_MAX;
    }

    // If this subproblem has been solved before, return its value from dpArray
    if (dpArray[x] != -1)
    {
        return dpArray[x];
    }

    int mini = INT_MAX;

    // Check each element in num to find the minimum combination
    for (int i = 0; i < num.size(); i++)
    {
        // Recursive call with reduced target
        int ans = findMinDp(num, x - num[i], dpArray);

        // If a valid combination was found, update mini with the minimum number of elements
        if (ans != INT_MAX)
        {
            mini = min(mini, 1 + ans);
        }
    }

    // Store the computed result in dpArray
    dpArray[x] = mini;
    return mini;
}

// DP approach: Tabulation method to build up the solution iteratively
int findMinTabulation(vector<int> &num, int x)
{
    // dp[i] represents the minimum number of elements required to reach the sum i
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0; // Base case: zero elements required to reach a sum of 0

    // Iterate over all possible sums from 1 to x
    for (int i = 1; i <= x; i++)
    {
        for (int j = 0; j < num.size(); j++)
        {
            // Check if num[j] can contribute to the sum i
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
            }
        }
    }

    return dp[x];
}

// Main function to calculate the minimum elements needed to reach sum x
int minimumElements(vector<int> &num, int x)
{
    // Method 1: Recursive solution
    // int ans = findMin(num, x);

    // Method 2: Recursion with memoization
    // vector<int> dpArray(x + 1, -1);
    // int ans = findMinDp(num, x, dpArray);

    // Method 3: Tabulation (Bottom-Up DP)
    int ans = findMinTabulation(num, x);

    // If the result is INT_MAX, it means no valid combination was found
    if (ans != INT_MAX)
    {
        return ans;
    }
    return -1; // Return -1 if it’s not possible to form the sum x
}

int main()
{
    // Input number of elements in the array
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    // Input array elements
    vector<int> num(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    // Input target sum x
    int x;
    cout << "Enter the target sum: ";
    cin >> x;

    // Calculate and display the minimum number of elements required
    int result = minimumElements(num, x);
    if (result != -1)
    {
        cout << "Minimum number of elements to reach the target sum: " << result << endl;
    }
    else
    {
        cout << "It's not possible to reach the target sum with the given elements." << endl;
    }

    return 0;
}
