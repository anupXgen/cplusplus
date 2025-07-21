/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4

*/

#include <iostream>
using namespace std;

int binarySearch(vector<int>& nums, int target) {
    int startIndex = 0;
    int endIndex = nums.size() - 1;
    int mid = startIndex + (endIndex - startIndex) / 2;

    if(target < nums[0]){
        return 0;
    }
    else if(target > nums[endIndex]){
        return endIndex + 1;
    }
    while (startIndex <= endIndex) {
        mid = startIndex + (endIndex - startIndex) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (target < nums[mid]) {
            endIndex = mid - 1; // Search left
        } else {
            startIndex = mid + 1; // Search right
        }
    }

    if(target < nums[mid]){
        return mid;
    }
    return mid + 1; // Not found
}

int main() {
    vector<int> arr = {1,3,5,6};
    int size = arr.size();
    int target = 5;

    int bs = binarySearch(arr, target);
    cout << "Index >> " << bs << endl;
}
