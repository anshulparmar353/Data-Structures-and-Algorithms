#include <iostream>
#include <vector>
using namespace std;

int peakInMountainOfUnsortedArr(vector<int> &input){
    int n = input.size();
    int lo = 0;
    int hi = n - 1;

    while (lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if (mid == 0){
            if (input[mid] > input[mid + 1]){
                return 0;
            }
            else{
                return 1;
            }
        }
        else if (mid == n - 1){
            if (input[mid] > input[mid - 1]){
                return n - 1;
            }
            else{
                return n - 2;
            }
        }
        else{
            if(input[mid] > input[mid+1] && input[mid] > input[mid-1]){
                return mid;
            }else if(input[mid] > input[mid-1]){
                lo = mid +1;
            }else{
                hi = mid-1;
            }
        }
    }
    return -1;
}

int main(){

    vector<int> input;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        input.push_back(x);
    }

    cout << peakInMountainOfUnsortedArr(input) << endl;

    return 0;
}