# Count the Number of Fair Pairs (All Approaches Implemented)
- ## Problem Intuition
    The task is to count the number of pairs in an array `nums` whose sum lies within a given range `[lower, upper]`. We need to find pairs `(i, j)` where:
    - `nums[i] + nums[j]` is between `lower` and `upper` (inclusive).
    - `i` and `j` are distinct indices.

    Given that the array size `n` can be large, a brute force solution that checks all pairs would be inefficient. Instead, we use a more efficient approach involving **binary search** to narrow down the valid pairs.

- ## Approach 1:- Linear Search (Time Limit Exceeded)

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
            - Inner loop: For each iteration of the outer loop, the inner loop iterates `n-1`, `n-2`, ... times, resulting in a total of $$\left(\frac{n\times(n-1)}{2}\right)$$ iterations.
            - The time complexity is therefore **O(n<sup>2</sup>)**.

    - ### Space Complexity
        The space complexity is **O(1)**, aside from the space required for the input array `nums`. This is because we only use a few extra variables (`total_Pairs`, `currentIndex`, `nextIndex`, `sum`), all of which occupy constant space. No additional data structures are used, and the input array itself is not modified.

        - **Space Complexity Breakdown:**
            - The space used by the variables `total_Pairs`, `currentIndex`, `nextIndex`, and `sum` is constant.
            - The space complexity is therefore **O(1)**.

- ## Approach 2:- Binary Search

    - ### Approach
        1. **Sorting**:
            - We start by **sorting** the array `nums` in non-decreasing order. Sorting helps us to efficiently find pairs using binary search.
        2. **Binary Search**:
            - For each element `nums[i]`, we want to find all elements `nums[j]` (where `j > i`) such that `nums[i] + nums[j]` falls within the range `[lower, upper]`.
            - We use binary search to efficiently find:
                - The **lower bound**: the smallest index `j` where `nums[i] + nums[j] >= lower`.
                - The **upper bound**: the largest index `j` where `nums[i] + nums[j] <= upper`.
            - These bounds are determined using binary search in the subarray from index `i+1` to the end of the array.
        3. **Count Valid Pairs**:
            - Once the bounds for a given `nums[i]` are determined, the valid pairs for that element are all the elements between the lower and upper bounds.
            - The number of valid pairs for `nums[i]` is simply the difference between the bounds (`upperBound - lowerBound + 1`).
        4. **Result**:
            - We repeat this process for each element in the sorted array and accumulate the total number of valid pairs.

        By using binary search instead of iterating through all possible pairs, we reduce the time complexity significantly.

    - ### Code
        - **Python Solution**
            
            ```python3 []
            class Solution:
                def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
                    
                    # Helper function to find the lower and upper bounds for valid pair sums
                    def find_lower_And_Upper_Bounds(startIndex: int, endIndex: int, currentIndex: int) -> Set[int]:
                        
                        # Initialize the bounds as -1 (invalid indices)
                        lowerBound, upperBound = -1, -1

                        # Use binary search to find the lower bound
                        left, right = startIndex, endIndex
                        while left <= right:
                            mid = (left + right) // 2
                            # If the sum of nums[mid] + nums[currentIndex] is greater than or equal to the lower bound
                            # We update the lowerBound and search left half
                            if nums[mid] + nums[currentIndex] >= lower:
                                lowerBound = mid
                                right = mid - 1
                            else:
                                # Otherwise, move the left pointer to mid + 1 to search the right half
                                left = mid + 1

                        # Use binary search to find the upper bound
                        left, right = startIndex, endIndex
                        while left <= right:
                            mid = (left + right) // 2
                            # If the sum of nums[mid] + nums[currentIndex] is less than or equal to the upper bound
                            # We update the upperBound and search right half
                            if nums[mid] + nums[currentIndex] <= upper:
                                upperBound = mid
                                left = mid + 1
                            else:
                                # Otherwise, move the right pointer to mid - 1 to search the left half
                                right = mid - 1

                        # Return the found bounds as a set
                        return lowerBound, upperBound
                    
                    
                    # Initialize a counter for the number of valid pairs
                    total_Pairs = 0
                    # Get the length of the input list
                    n = len(nums)
                    
                    # Sort the input array to facilitate binary search
                    nums.sort()
                    
                    # Loop through each element of the sorted array
                    for currentIndex in range(n):
                        # For each element, find the lower and upper bounds of valid pairs using binary search
                        lowerBound, upperBound = find_lower_And_Upper_Bounds(currentIndex + 1, n - 1, currentIndex)
                        
                        # If the bounds are valid (lowerBound <= upperBound and within array indices), count the valid pairs
                        if 0 <= lowerBound <= upperBound:
                            # The number of valid pairs is the difference between the bounds, plus 1 (inclusive range)
                            total_Pairs += (upperBound - lowerBound + 1)

                    # Return the total count of valid pairs
                    return total_Pairs
            ```
        
        - **C++ Solution**

            ```C++ []
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
            ```

    - ### Time Complexity
        1. **Sorting** the array takes **O(n log n)** time.
        2. For each element `nums[i]`, finding the **lower and upper bounds** using binary search takes **O(log n)** time. Since we perform this binary search for each element, the total time spent on binary searches is **O(n log n)**.
        3. Therefore, the overall time complexity is **O(n log n)**, where `n` is the number of elements in the array.

        - **Time Complexity Breakdown:**
            - Sorting the array: **O(n log n)**.
            - Binary search for each element: **O(log n)**, performed for all `n` elements, leading to **O(n log n)**.

        Thus, the total time complexity is **O(n log n)**.

    - ### Space Complexity
        The space complexity is **O(1)**, aside from the space used by the input array `nums`. This is because:
        - We use a fixed amount of extra space for variables like `total_Pairs`, `lowerBound`, `upperBound`, and other temporary variables.
        - We do not use any additional data structures, so the space complexity is constant.

        - **Space Complexity Breakdown:**
            - The space used by variables such as `total_Pairs`, `lowerBound`, `upperBound`, and the pointers for binary search is constant.
            - The space complexity is therefore **O(1)**.