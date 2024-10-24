#include <iostream>
using namespace std;

class BinarySearch {
public:
    // Iterative Binary Search
    int iterativeBinarySearch(int arr[], int left, int right, int target) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // If element is found at middle
            if (arr[mid] == target)
                return mid;
            
            // If element is greater, ignore left half
            if (arr[mid] < target)
                left = mid + 1;
            
            // If element is smaller, ignore right half
            else
                right = mid - 1;
        }
        
        // Element not found
        return -1;
    }
    
    // Recursive Binary Search
    int recursiveBinarySearch(int arr[], int left, int right, int target) {
        if (right >= left) {
            int mid = left + (right - left) / 2;
            
            // If element is found at middle
            if (arr[mid] == target)
                return mid;
            
            // If element is smaller than mid, search in left subarray
            if (arr[mid] > target)
                return recursiveBinarySearch(arr, left, mid - 1, target);
            
            // Else search in right subarray
            return recursiveBinarySearch(arr, mid + 1, right, target);
        }
        
        // Element not found
        return -1;
    }
};

int main() {
    BinarySearch bs;
    int arr[] = {2, 3, 4, 10, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    
    // Iterative Binary Search
    int iterativeResult = bs.iterativeBinarySearch(arr, 0, n-1, target);
    if (iterativeResult == -1)
        cout << "Element not found (Iterative)" << endl;
    else
        cout << "Element found at index " << iterativeResult << " (Iterative)" << endl;
    
    // Recursive Binary Search
    int recursiveResult = bs.recursiveBinarySearch(arr, 0, n-1, target);
    if (recursiveResult == -1)
        cout << "Element not found (Recursive)" << endl;
    else
        cout << "Element found at index " << recursiveResult << " (Recursive)" << endl;
    
    return 0;
}
