
#include <iostream>
#include <vector>
using namespace std;

void printSubsequence(const vector<int> &nums, int index, int k, vector<int> &subsequence, int sum, bool &found) {
    if (index == nums.size()) {
        if (sum == k) {
            cout << "[ ";
            for (int x : subsequence) cout << x << " ";
            cout << "]" << endl;
            found = true;
        }
        return;
    }

    // Include
    subsequence.push_back(nums[index]);
    printSubsequence(nums, index + 1, k, subsequence, sum + nums[index], found);
    subsequence.pop_back();

    // Exclude
    printSubsequence(nums, index + 1, k, subsequence, sum, found);
}

int main() {
    vector<int> nums;
    cout << "Enter the elements (-1 to stop): ";
    int data, k;
    while (true) {
        cin >> data;
        if (data == -1) break;
        nums.push_back(data);
    }

    cout << "Enter the value of K: ";
    cin >> k;

    vector<int> result;
    bool found = false;

    printSubsequence(nums, 0, k, result, 0, found);

    if (!found) {
        cout << "No subsequence sums to " << k << endl;
    }
    return 0;
}
