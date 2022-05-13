// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

// Example 1:
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Solution: TC: O(N) SC: O(1)

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int zero = 0, one = 0, two = n - 1;

        while (one <= two)
        {
            if (nums[one] == 0)
            {
                swap(nums[one++], nums[zero++]);
            }
            else if (nums[one] == 2)
            {
                swap(nums[one], nums[two--]);
            }
            else
            {
                one++;
            }
        }
    }
};