/**
 * Allocation of books to the students so that maximum pages allocated are the minimum
 * 
 */

 #include <vector>
 #include <iostream>

 using namespace std;

 bool isValid(vector<int>& nums, int maxAllocation, int students){ //O(n)
    int stCounter = 1, pages = 0;
    int n = nums.size();

    for(int i = 0; i<n; i++){
        //Edge Case
        if(nums[i] > maxAllocation)
            return false;

        //checking if the maximum allowed pages are not crossed
        if((pages + nums[i]) <= maxAllocation){
            pages = pages + nums[i]; //allocation of the pages to the students
        }else{
            //once the maximum allowed pages crossed then allocate the books to new student
            stCounter++;
            pages = nums[i];
        }
    }

    //cout << "Max Allowed >> " << maxAllocation << endl;
    //cout << "St Counter >> " << stCounter << endl;

    return stCounter <= students;
 }


 
 int sumOfArray(vector<int>& nums){
    int sum = 0;
    int n = nums.size();
    for(int i = 0; i<n; i++){
        sum = sum + nums[i];
    }
    return sum;
 }

 int bookAllocation(vector<int>& nums, int students){ //O(log N)
    int sum = sumOfArray(nums); //finding out the sum of the array
    int start = 0;
    int end = sum;
    int mid = 0;
    int ans = -1;

    //now my numbers are arranged in sorted order and we can perform binary search for the maximum pages allocation to a student
    while(start <= end){
        mid = start + ((end - start)/2);
        //check if the mid is valid or not (can be allocated to the given students or not)
        if(isValid(nums, mid, students)){
            ans = mid; //store the value of the valid maximum pages allocation
            end = mid - 1; //if the pages allocation is valid then you need to check are there any minimum than the valid value
        }
        else{
            start = mid + 1; //if the pages allocation is not valid then we need to keep searching the maximum pages allocation
        }
    }
    

    return ans;
 }

 
 int main(){ //O(nlog N)
    vector<int> nums = {15, 17, 20};
    int students = 2;
    cout << "Ans >> " << bookAllocation(nums, students) << endl;
 }
