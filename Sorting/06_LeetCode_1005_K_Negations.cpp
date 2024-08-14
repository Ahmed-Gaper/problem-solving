#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());  // Sort the array
        for (int i = 0; i < nums.size() && k > 0; i++) {
            if (nums[i] < 0) {  // Only negate if the number is negative
                nums[i] = -nums[i];  // Negate the number
                k--;  // Decrement k for each negation
            }
        }

        // If there are any negations left
        if (k > 0) {
            if (k % 2 == 1) {  // If k is odd, we need to negate the smallest absolute value
                // Find the minimum element
                int minIndex = min_element(nums.begin(), nums.end()) - nums.begin();
                nums[minIndex] = -nums[minIndex];
            }
        }

        int sum = accumulate(nums.begin(), nums.end(), 0);  // Calculate the final sum
        return sum;
    }
};

int main() {
    vector<int> dis{2, -3, -1, 5, -4};
    Solution s;
    cout << s.largestSumAfterKNegations(dis, 2);  // Output: 13

    return 0;
}
