#include <iostream>
#include <vector>
#define mod 1000000007
using namespace std;

// Normal recursion (inefficient for large n due to overlapping subproblems)
int numberOfWays(int n, int k)
{
    if (n == 1)
        return k;

    if (n == 2)
        return (1LL * k * k) % mod;

    return (1LL * (k - 1) * (numberOfWays(n - 1, k) + numberOfWays(n - 2, k)) % mod) % mod;
}

// DP method using recursion + memoization to avoid redundant calculations
int solveDP(int n, int k, vector<int> &dp)
{
    if (n == 1)
        return k;

    if (n == 2)
        return (1LL * k * k) % mod;

    if (dp[n] != -1) // Check if already computed
        return dp[n];

    dp[n] = (1LL * (k - 1) * (solveDP(n - 1, k, dp) + solveDP(n - 2, k, dp)) % mod) % mod;
    return dp[n];
}

// Tabulation method using a bottom-up DP approach
int solveTab(int n, int k)
{
    vector<int> dp(n + 1);

    dp[1] = k;
    dp[2] = (1LL * k * k) % mod;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = (1LL * (k - 1) * (dp[i - 1] + dp[i - 2]) % mod) % mod;
    }

    return dp[n];
}

// Space-optimized method using only two variables
int solveSpaceOptimized(int n, int k)
{
    if (n == 1)
        return k;
    if (n == 2)
        return (1LL * k * k) % mod;

    int prev2 = k;                   // dp[i-2]
    int prev1 = (1LL * k * k) % mod; // dp[i-1]
    int curr;

    for (int i = 3; i <= n; i++)
    {
        curr = (1LL * (k - 1) * (prev1 + prev2) % mod) % mod;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main()
{
    int n, k;
    cout << "Enter the number of fence posts (n): ";
    cin >> n;
    cout << "Enter the number of colors (k): ";
    cin >> k;

    cout << "Number of ways using normal recursion: " << numberOfWays(n, k) << endl;

    vector<int> dp(n + 1, -1);
    cout << "Number of ways using DP (memoization): " << solveDP(n, k, dp) << endl;

    cout << "Number of ways using DP (tabulation): " << solveTab(n, k) << endl;

    cout << "Number of ways using space optimization: " << solveSpaceOptimized(n, k) << endl;

    return 0;
}
