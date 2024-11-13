from typing import List

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