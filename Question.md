# [2563. Count the Number of Fair Pairs](https://leetcode.com/problems/count-the-number-of-fair-pairs)

__Type:__ Medium <br>
__Topics:__ Array, Two Pointers, Binary Search, Sorting <br>
__Companies:__ Salesforce, Google, Amazon
<hr>

Given a __0-indexed__ integer array `nums` of size `n` and two integers `lower` and `upper`, return _the number of fair pairs_.

A pair `(i, j)` is __fair__ if:

- `0 <= i < j < n`, and
- `lower <= nums[i] + nums[j] <= upper`
<hr>

### Examples:

- __Example 1:__ <br>
__Input:__ nums = [0,1,7,4,4,5], lower = 3, upper = 6 <br>
__Output:__ 6 <br>
__Explanation:__ There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).

- __Example 2:__ <br>
__Input:__ nums = [1,7,9,2,5], lower = 11, upper = 11 <br>
__Output:__ 1 <br>
__Explanation:__ There is a single fair pair: (2,3).
<hr>

### Constraints:
- <code>1 <= nums.length <= 10<sup>5</sup></code>
- `nums.length == n`
- <code>-10<sup>9</sup> <= nums[i] <= 10<sup>9</sup></code>
- <code>-10<sup>9</sup> <= lower <= upper <= 10<sup>9</sup></code>
<hr>

### Hints:
- Sort the array in ascending order.
- For each number in the array, keep track of the smallest and largest numbers in the array that can form a fair pair with this number.
- As you move to larger number, both boundaries move down.