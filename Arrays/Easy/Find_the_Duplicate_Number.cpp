// Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
// There is only one repeated number in nums, return this repeated number.
// You must solve the problem without modifying the array nums and uses only constant extra space.

// Example 1:
// Input: nums = [1,3,4,2,2]
// Output: 2

// Solution 1: TC: OO(N) SC: O(N)
class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size() - 1;
        vector<int> hash(n + 1, 0);

        for (auto x : nums)
        {
            if (hash[x] > 0)
            {
                return x;
            }
            hash[x]++;
        }

        return -1;
    }
};

// Solution 2: TC: OO(N) SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        if (nums.size() > 1)
        {
            int slow = nums[0];
            int fast = nums[nums[0]];

            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            fast = 0;

            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[fast];
            }

            return slow;
        }

        return -1;
    }
};