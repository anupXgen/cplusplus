/**
 * Given a positive integer num, return true if num is a perfect square or false otherwise.

A perfect square is an integer that is the square of an integer. In other words, it is the product of some integer with itself.

You must not use any built-in library function, such as sqrt.

 

Example 1:

Input: num = 16
Output: true
Explanation: We return true because 4 * 4 = 16 and 4 is an integer.

Example 2:

Input: num = 14
Output: false
Explanation: We return false because 3.742 * 3.742 = 14 and 3.742 is not an integer.

 

Constraints:

    1 <= num <= 231 - 1


 */

#include <iostream>
using namespace std;

bool isPerfectSquare(int num){

    int start = 0;
    int end = num;
    int mid = 0;
    int ans = 0;
    long long int sq = 1;

    
    while(start <= end){
        mid = start + (end - start)/2;
        sq = 1LL * mid * mid;
        if(sq > num){
            end = mid - 1;
        }
        else {
            ans = mid;
            start = mid + 1;
        }

        if(sq == num){
            return true;
        }

    }

    return false;
}

int main(){

cout << "Perfect Square >>> " << isPerfectSquare(4) << endl;

}