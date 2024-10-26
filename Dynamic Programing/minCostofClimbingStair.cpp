// 746. Min Cost Climbing Stairs (LeetCode)
/*
You are given an integer array cost where cost[i] is the cost of ith step on a staircase.
Once you pay the cost, you can either climb one or two steps.
You can either start from the step with index 0 or the step with index 1.
Return the minimum cost to reach the top of the floor.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
private:
    // Normal recursion approach
    int minCost(vector<int> &cost, int n)
    {
        // Base case: if we're at the first or second stair, return the cost directly
        if (n == 0 || n == 1)
        {
            return cost[n];
        }

        // Recursive case: calculate the cost to reach the nth stair from n-1 or n-2
        int ans = cost[n] + min(minCost(cost, n - 1), minCost(cost, n - 2));
        return ans;
    }

    // 2nd method: Dynamic Programming using recursion and memoization
    int minCostDp1(vector<int> &cost, int n, vector<int> &dpArray)
    {
        // Base case: if we're at the first or second stair, return the cost directly
        if (n == 0 || n == 1)
        {
            return cost[n];
        }

        // Check if the result is already computed and stored in dpArray
        if (dpArray[n] != -1)
        {
            return dpArray[n];
        }

        // Recursive case: calculate the cost to reach the nth stair from n-1 or n-2
        dpArray[n] = cost[n] + min(minCostDp1(cost, n - 1, dpArray), minCostDp1(cost, n - 2, dpArray));
        return dpArray[n];
    }

    // 3rd method: Dynamic Programming Tabulation Method
    int minCostDp2(vector<int> &cost, int n)
    {
        vector<int> dp(n + 1); // DP array to store minimum cost for each step
        // Base case: initialize the first two stairs' costs
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Fill the dp array using the previously computed values
        for (int i = 2; i < n; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }

        // Return the minimum cost to reach the top
        return min(dp[n - 1], dp[n - 2]);
    }

    // Space optimized method
    int minCostDp3(vector<int> &cost, int n)
    {
        int x = cost[0]; // Cost to reach the first stair
        int y = cost[1]; // Cost to reach the second stair

        // Iterate through each stair starting from the third
        for (int i = 2; i < n; i++)
        {
            int curr = cost[i] + min(x, y); // Current cost
            x = y;                          // Update x to the previous stair's cost
            y = curr;                       // Update y to the current cost
        }
        // Return the minimum cost to reach the top
        return min(x, y);
    }

public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size(); // Get the number of stairs

        vector<int> dpArray(n + 1, -1); // Initialize DP array for memoization

        // Uncomment to use different methods:
        // return min(minCost(cost, n - 1), minCost(cost, n - 2)); // Normal Recursion
        // return min(minCostDp1(cost, n - 1, dpArray), minCostDp1(cost, n - 2, dpArray)); // Memoization
        return minCostDp3(cost, n); // Space Optimized DP
    }
};

int main()
{
    // Input number of stairs
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;

    vector<int> cost(n); // Vector to hold costs for each stair

    // Input costs for each stair
    cout << "Enter the cost of stairs: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Cost of " << i << "th stair: ";
        cin >> cost[i];
    }

    // Create an instance of Solution
    Solution solution;

    // Calculate and output the minimum cost to reach the top
    int result = solution.minCostClimbingStairs(cost);
    cout << "Minimum cost to climb the stairs: " << result << endl;

    return 0;
}
