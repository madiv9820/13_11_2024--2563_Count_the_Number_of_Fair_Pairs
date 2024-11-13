#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // Initialize the total number of valid pairs
        long long total_Pairs = 0;
        // Get the size of the input array
        int n = nums.size();

        // Iterate through each element in the array using 'currentIndex'
        for (int currentIndex = 0; currentIndex < n; ++currentIndex) {
            // For each element at currentIndex, check all subsequent elements using 'nextIndex'
            for (int nextIndex = currentIndex + 1; nextIndex < n; ++nextIndex) {
                // Calculate the sum of the pair (nums[currentIndex], nums[nextIndex])
                int sum = nums[currentIndex] + nums[nextIndex];
                
                // Check if the sum is within the specified range [lower, upper]
                if (sum >= lower && sum <= upper) {
                    // If valid, increment the total pair count
                    ++total_Pairs;
                }
            }
        }

        // Return the total number of valid pairs
        return total_Pairs;
    }
};

int main() {
    vector<int> nums; Solution sol;
    int lower, upper, input;
    cin >> input;

    while(input != -1) {
        nums.emplace_back(input);
        cin >> input;
    }

    cin >> lower >> upper;
    cout << sol.countFairPairs(nums = nums, lower = lower, upper = upper) << endl;
}