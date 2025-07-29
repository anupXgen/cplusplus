/**
 * Peak Index in Mountain Array
 * arr = [0,3,8,9,5,2]
 * 
 * 
 */

 #include <iostream>
 #include <vector>

 using namespace std;

 int findPeakIndex(vector<int>& arr){

    int startIndex = 0;
    int endIndex = arr.size() - 1;
    int mid = 0;
    int ans = -1;
    while(startIndex <= endIndex){
        mid = startIndex + ((endIndex - startIndex)/2);
        if(arr[mid] > arr[mid+1] && arr[mid] > arr[mid - 1]){
            ans = mid;
            return ans;
        }
        else if(arr[mid] < arr[mid+1]){
            startIndex = mid + 1;
            ans = mid;
        }else if(arr[mid] < arr[mid - 1]){
            ans = mid;
            endIndex = mid - 1;

        }
       
    }

    return ans;
 }
 
 
 int main(){
    vector<int> arr = {0,1,0};
    cout << "Peak Index >>" << findPeakIndex(arr) << endl;
 } 