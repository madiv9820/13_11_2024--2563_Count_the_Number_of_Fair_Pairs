from typing import List, Set

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