/**
 * You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.



Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2

Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10



Constraints:

    1 <= nums.length <= 105
    0 <= nums[i] <= 105


 */

#include <iostream>
#include <vector>
using namespace std;

int singleNonDuplicate(vector<int> &nums)
{

    int startIndex = 0;
    int endIndex = nums.size() - 1;
    int mid = 0;
    int ans = -1;
    int startArrlength = 0;
    int endArrlength = 0;
    int n = nums.size();

    if (n == 1)
        return nums[0];

    while (startIndex <= endIndex)
    {
        mid = startIndex + ((endIndex - startIndex) / 2);

        if (mid == 0 && nums[0] != nums[1])
            return nums[mid];

        if (mid == (n - 1) && nums[n - 1] != nums[n - 2])
            return nums[mid];

        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
            return nums[mid];

        // check whether array is odd or even
        if (mid % 2 == 0)
        {
            // check whether previous value matches the current one
            if (nums[mid - 1] == nums[mid])
            {
                // move to left
                endIndex = mid - 1;
                ans = nums[endIndex];
            }
            else
            {
                // move to right
                startIndex = mid + 1;
                ans = nums[startIndex];
            }
        }
        else
        {
            if (nums[mid - 1] == nums[mid])
            {
                // move to right
                startIndex = mid + 1;
                ans = nums[startIndex];
            }
            else
            {
                endIndex = mid - 1;
                ans = nums[endIndex];
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};

    cout << "Ans >> " << singleNonDuplicate(nums) << endl;
}