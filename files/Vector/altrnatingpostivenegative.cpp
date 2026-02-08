#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void alternatePositiveNegative(vector<int>& arr) {
    // Separate positive and negative numbers
    vector<int> positive, negative;
    
    for (int num : arr) {
        if (num > 0) {
            positive.push_back(num);
        } else if (num < 0) {
            negative.push_back(num);
        }
    }

    // Merge them alternately
    int i = 0, j = 0;
    vector<int> result;
    
    // Alternate the positive and negative numbers
    while (i < positive.size() && j < negative.size()) {
        result.push_back(positive[i++]);
        result.push_back(negative[j++]);
    }
    
    // Append any remaining elements
    while (i < positive.size()) {
        result.push_back(positive[i++]);
    }
    
    while (j < negative.size()) {
        result.push_back(negative[j++]);
    }
    
    // Copy the result back to the original array
    arr = result;
}

int main() {
    vector<int> arr = {8,-2,-6,2,-4,5,-3,7};
    
    alternatePositiveNegative(arr);

    // Print the result
    for (int num : arr) {
        cout << num << " ";
    }

    return 0;
}
