/*
Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

Example 1:

Input: nums = [3,0,1]

Output: 2

Explanation:

n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:

Input: nums = [0,1]

Output: 2

Explanation:

n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]

Output: 8

Explanation:

n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

*/


#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> nums = {0,1};
    int actualSum = 0;
    int arrSum = 0;
    int ans = 0;
    //find the max number for range
    int max = nums.size();
    for(int i=0; i<nums.size();i++){
        arrSum += nums[i];
    }
    //find the. total sum based on the range
    for(int i=0; i<= max;i++){
        actualSum += i; 
    }

    //find the difference and identify the number
    ans = actualSum - arrSum;

    cout << "Answer :: " << ans << endl;
    return ans;
}