#include <iostream>
#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        
        // Lambda function to find the lower and upper bounds of valid pairs
        function<pair<int,int>(int,int,int)> find_lower_And_Upper_Bounds = [&](int startIndex, int endIndex, int currentIndex) -> pair<int, int> {
            
            // Initialize the bounds with -1 (indicating invalid indices initially)
            pair<int,int> bounds = {-1,-1};

            // Perform binary search to find the lower bound
            int left = startIndex, right = endIndex;
            while(left <= right) {
                int mid = (left + right) / 2;
                // If nums[mid] + nums[currentIndex] is greater than or equal to the lower bound
                // We update the lower bound and continue searching the left side
                if(nums[mid] + nums[currentIndex] >= lower) {
                    bounds.first = mid; // Update lower bound
                    right = mid - 1; // Narrow the search to the left side
                } else {
                    // Otherwise, move the left pointer to mid+1 to search the right side
                    left = mid + 1;
                }
            }

            // Perform binary search to find the upper bound
            left = startIndex, right = endIndex;
            while(left <= right) {
                int mid = (left + right) / 2;
                // If nums[mid] + nums[currentIndex] is less than or equal to the upper bound
                // We update the upper bound and continue searching the right side
                if(nums[mid] + nums[currentIndex] <= upper) {
                    bounds.second = mid; // Update upper bound
                    left = mid + 1; // Narrow the search to the right side
                } else {
                    // Otherwise, move the right pointer to mid-1 to search the left side
                    right = mid - 1;
                }
            }

            // Return the found bounds as a pair
            return bounds;
        };

        // Initialize total_Pairs to count the number of valid pairs
        long long total_Pairs = 0;
        int n = nums.size();

        // Sort the array to enable binary search
        sort(nums.begin(), nums.end());

        // Iterate through the array to check all possible pairs
        for(int currentIndex = 0; currentIndex < n; ++currentIndex) {
            // Find the valid bounds for the pair nums[currentIndex] + nums[i] using binary search
            pair<int,int> bounds = find_lower_And_Upper_Bounds(currentIndex + 1, n - 1, currentIndex);
            int lowerBound = bounds.first, upperBound = bounds.second;
            
            // If valid bounds are found (lowerBound <= upperBound), count the number of valid pairs
            if(0 <= lowerBound && lowerBound <= upperBound) {
                total_Pairs += (upperBound - lowerBound + 1);
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