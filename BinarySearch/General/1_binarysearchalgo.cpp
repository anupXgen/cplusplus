#include <iostream>
using namespace std;

int binarySearch(vector<int> arr, int size, int target) {
    int startIndex = 0;
    int endIndex = size - 1;

    while (startIndex <= endIndex) {
        int mid = startIndex + (endIndex - startIndex) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (target < arr[mid]) {
            endIndex = mid - 1; // Search left
        } else {
            startIndex = mid + 1; // Search right
        }
    }

    return -1; // Not found
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int size = arr.size();
    int target = 3;

    int bs = binarySearch(arr, size, target);
    cout << "Index >> " << bs << endl;
}
