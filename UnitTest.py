from Solution import Solution
import unittest
from timeout_decorator import timeout

class UnitTest(unittest.TestCase):
    def setUp(self):
        self.__testCases = {1: ([0,1,7,4,4,5], 3, 6, 6), 2: ([1,7,9,2,5], 11, 11, 1)}
        self.__obj = Solution()
        return super().setUp()
    
    @timeout(0.5)
    def __test_Case1(self):
        nums, lower, upper, output = self.__testCases[1]
        result = self.__obj.countFairPairs(nums = nums, lower = lower, upper = upper)
        self.assertIsInstance(result, int)
        self.assertEqual(result, output)
    
    @timeout(0.5)
    def __test_Case2(self):
        nums, lower, upper, output = self.__testCases[2]
        result = self.__obj.countFairPairs(nums = nums, lower = lower, upper = upper)
        self.assertIsInstance(result, int)
        self.assertEqual(result, output)

if __name__ == '__main__': unittest.main()