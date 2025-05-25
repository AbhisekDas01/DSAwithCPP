#include <iostream>
#include <vector>
using namespace std;

int matrixMultiplication(vector<int> &arr, int start, int end, vector<vector<int>> &dp)
{

    if (start >= end)
        return 0;

    if (dp[start][end] != -1)
        return dp[start][end];

    int mini = 1e9;

    for (int k = start; k < end; k++)
    {
        int steps = arr[start - 1] * arr[k] * arr[end] + matrixMultiplication(arr, start, k, dp) + matrixMultiplication(arr, k + 1, end, dp);

        mini = min(mini, steps);
    }

    return dp[start][end] = mini;
}

int matrixChainMultiplicationTabulation(vector<int> &arr)
{

    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int start = n - 1; start >= 1; start--)
    {
        for (int end = start + 1; end < n; end++)
        {

            int mini = 1e9;

            for (int k = start; k < end; k++)
            {
                int steps = arr[start - 1] * arr[k] * arr[end] + dp[start][k] + dp[k + 1][end];

                mini = min(mini, steps);
            }

            dp[start][end] = mini;
        }
    }

    return dp[1][n-1];
}
int main()
{
    int n;
    cout << "Enter the number of matrices + 1 (size of dimensions array): ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " dimensions: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));

    // int minOperations = matrixMultiplication(arr, 1, n - 1, dp);
    int minOperations = matrixChainMultiplicationTabulation(arr);
    cout << "Minimum number of operations: " << minOperations << endl;

    return 0;
}