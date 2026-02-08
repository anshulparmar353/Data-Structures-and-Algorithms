#include<iostream>
#include<vector>
using namespace std;

bool findNum(vector<int> &arr, int n, int target){
    // Edge case: If the array has only one element, check directly
    if(n == 1) {
        return arr[0] == target;
    }

    int lo = 0;
    int hi = n - 1;

    while(lo <= hi){
        // Finding mid
        int mid = lo + (hi - lo) / 2;

        // If the element is found at mid
        if(arr[mid] == target) {
            return true;
        }

        // If left part is sorted
        if(arr[lo] <= arr[mid]) {
            // Check if the target lies in the left part
            if(arr[lo] <= target && target < arr[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        // If right part is sorted
        else {
            // Check if the target lies in the right part
            if(arr[mid] < target && target <= arr[hi]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }
    return false;
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int target;
    cin >> target;

    cout << findNum(arr, n, target) << endl;

    return 0;
}
