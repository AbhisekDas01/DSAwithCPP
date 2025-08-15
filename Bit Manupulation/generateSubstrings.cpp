/**
 * Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

All the numbers of nums are unique.
 */

#include <iostream>
#include <vector>
using namespace std;

// Generate all subsets (power set) using bit masking.
// For n elements, there are 2^n masks. For each mask, bit j tells whether to include nums[j].
vector<vector<int>> subsets(vector<int> &nums) {
    vector<vector<int>> result;
    int n = nums.size();
    int power = 1 << n; // total number of subsets = 2^n

    vector<int> temp;
    for (int mask = 0; mask < power; ++mask) {
        // Build current subset based on set bits in mask
        for (int j = 0; j < n; ++j) {
            if (mask & (1 << j)) {
                temp.push_back(nums[j]);
            }
        }

        // Save current subset
        result.push_back(temp);

        // Reset for next subset
        temp.clear();
    }
    return result;
}

// Print subsets in the form: [[],[a],[b],[a,b],...]
void printSubsets(const vector<vector<int>>& sets) {
    cout << "[";
    for (int i = 0; i < sets.size(); ++i) {
        cout << "[";
        for (int j = 0; j < sets[i].size(); ++j) {
            cout << sets[i][j];
            if (j + 1 < sets[i].size()) cout << ",";
        }
        cout << "]";
        if (i + 1 < sets.size()) cout << ",";
    }
    cout << "]" << endl;
}

int main() {
    vector<int> nums;
    int data;

    cout << "Enter the set elements (-1 to stop): ";
    while (1) {
        cin >> data;
        if (data == -1) break;
        nums.push_back(data);
    }

    // Compute and print all subsets (power set)
    vector<vector<int>> all = subsets(nums);
    cout << "All subsets (power set):" << endl;
    printSubsets(all);

    return 0;
}