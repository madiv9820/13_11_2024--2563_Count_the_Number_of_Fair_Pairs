- ## Approach 1:- Linear Search (Time Limit Exceeded)

    - ### Problem Intuition
        The problem asks us to count how many pairs of numbers from an array `nums` have their sum within a specified range `[lower, upper]`. A valid pair consists of two distinct elements in the array, and their sum must satisfy the condition:  
        - `lower <= nums[currentIndex] + nums[nextIndex] <= upper`
        
        Where `currentIndex` and `nextIndex` are distinct indices from the array.

    - ### Approach
        To solve this problem, we will use a **Linear Search approach**:
        1. We will iterate through all possible pairs in the given array.
        2. For each pair, calculate the sum of the two elements.
        3. Check if the sum lies within the given range `[lower, upper]`.
        4. Count and return the number of valid pairs.

        The solution consists of two nested loops:
            - The outer loop iterates through the first element of the pair.
            - The inner loop iterates through all subsequent elements, forming pairs with the element from the outer loop.
            - For each pair, we check if the sum is within the specified range and update our counter accordingly.

    - ### Detailed Steps:
        1. Initialize a counter `total_Pairs` to 0.
        2. Use two nested loops to iterate over all pairs in the list `nums`.
        3. For each pair `(nums[currentIndex], nums[nextIndex])`, calculate the sum.
        4. If the sum is between `lower` and `upper` (inclusive), increment the `total_Pairs` counter.
        5. After all pairs are checked, return the `total_Pairs` as the result.

    - ### Code
        - **Python Solution**

            ```python3 []
            class Solution:
                def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
                    # Initialize a counter to keep track of valid pairs
                    total_Pairs = 0
                    
                    # Get the length of the list 'nums'
                    n = len(nums)

                    # Loop through the list using an index 'current_Index'
                    for currentIndex in range(n):
                        # Loop through the rest of the list starting from the next index 'current_Index + 1'
                        for nextIndex in range(currentIndex + 1, n):
                            # Check if the sum of the current pair is within the given range [lower, upper]
                            if lower <= nums[currentIndex] + nums[nextIndex] <= upper:
                                # If the condition is met, increment the pair counter
                                total_Pairs += 1

                    # Return the total number of valid pairs found
                    return total_Pairs
                
                    # You can do it one line too in python
                    '''return sum(1 for currentIndex in range(len(nums)) 
                                for nextIndex in range(currentIndex+1, len(nums)) 
                                if lower <= nums[currentIndex] + nums[nextIndex] <= upper)'''
            ```
        
        - **C++ Solution**

            ```C++ []
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
            ```

    - ### Time Complexity
        The time complexity of the above approach is **O(n<sup>2</sup>)**, where `n` is the length of the input array `nums`. This is because we are using two nested loops to check each pair of numbers in the array. For each pair, we are only doing constant time operations (calculating the sum and comparing it with the bounds).

        - **Time Complexity Breakdown:**
            - Outer loop: Iterates `n` times.
            - Inner loop: For each iteration of the outer loop, the inner loop iterates `n-1`, `n-2`, ... times, resulting in a total of 
                $$
                \frac{n(n-1)}{2}
                $$ 
            iterations.
            - The time complexity is therefore **O(n<sup>2</sup>)**.

    - ### Space Complexity
        The space complexity is **O(1)**, aside from the space required for the input array `nums`. This is because we only use a few extra variables (`total_Pairs`, `currentIndex`, `nextIndex`, `sum`), all of which occupy constant space. No additional data structures are used, and the input array itself is not modified.

        - **Space Complexity Breakdown:**
            - The space used by the variables `total_Pairs`, `currentIndex`, `nextIndex`, and `sum` is constant.
            - The space complexity is therefore **O(1)**.