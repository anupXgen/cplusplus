/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

    For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.

 

Example 1:

Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:

Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.

 

Constraints:

    0 <= x <= 231 - 1



*/

#include <iostream>
using namespace std;

int binarySearch(int x) {
    int startIndex = 0;
    int endIndex = x;
    int ans = 0;
    int mid = startIndex + (endIndex - startIndex) / 2;
    long long int sqr = 1;
    while (startIndex <= endIndex) {
        mid = startIndex + (endIndex - startIndex) / 2;
        sqr = 1LL * mid * mid; //squaring the mid
        if (sqr == x) {
            return mid;
        } else if (sqr < x) {
            ans = mid;
            startIndex = mid + 1;
        } else {
            endIndex = mid - 1;
        }
    }

    return ans; // Nearest to integer
}

int main() {
    vector<int> arr = {1,3,5,6};
    int size = arr.size();
    int x = 2147395599;

    int bs = binarySearch(x);
    cout << "Index >> " << bs << endl;
}
