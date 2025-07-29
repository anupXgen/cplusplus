/**
 * Allocation of boards to the painters in a contigous manner to calculate the minimum time required to complete the board
 * 
 */

 #include <vector>
 #include <iostream>

 using namespace std;

 bool isValid(vector<int>& nums, int maxAllocation, int painter){ //O(n)
    
    //cout << "Checking for >>> " << maxAllocation << endl;
    
    int ptCounter = 1, board = 0;
    int n = nums.size();

    for(int i = 0; i<n; i++){
        //Edge Case
        if(nums[i] > maxAllocation)
            return false;

        //checking if the maximum allowed pages are not crossed
        if((board + nums[i]) <= maxAllocation){
            board = board + nums[i]; //allocation of the pages to the students
        }else{
            //once the maximum allowed pages crossed then allocate the books to new student
            ptCounter++;
            board = nums[i];
        }
    }

    //cout << "Max Allowed >> " << maxAllocation << endl;
    //cout << "Painter Counter >> " << ptCounter << endl;

    return ptCounter <= painter;
 }


 
 int sumOfArray(vector<int>& nums){
    int sum = 0;
    int n = nums.size();
    for(int i = 0; i<n; i++){
        sum = sum + nums[i];
    }
    return sum;
 }

 int getMax(vector<int>& nums){
    int max = 0;
    for(int i =0; i<nums.size(); i++){
        if(nums[i] > max){
            max = nums[i];
        }
    }

    return max;
 }

 int boardAllocation(vector<int>& nums, int painter){ //O(log N)
    int sum = sumOfArray(nums); //finding out the sum of the array
    //cout << "Sum >>" << sum << endl;
    int start = getMax(nums);
    //cout << "Max >>" << start << endl;
    int end = sum;
    int mid = 0;
    int ans = -1;

    //now my numbers are arranged in sorted order and we can perform binary search for the maximum pages allocation to a student
    while(start <= end){
        mid = start + ((end - start)/2);
        //check if the mid is valid or not (can be allocated to the given students or not)
        if(isValid(nums, mid, painter)){
            //cout << "Valid >> mid =" << mid << endl; 
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
    vector<int> nums = {40, 30, 10, 20};
    int painter = 2;
    cout << "Ans >> " << boardAllocation(nums, painter) << endl;
 }
