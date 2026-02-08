#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void countSort(vector<int> &v){
    int n = v.size();
    // creating max elements
    int max_ele = INT_MIN;
    for (int i = 0; i < n; i++){
        max_ele = max(v[i], max_ele);
    }

    // creating frequency array
    vector<int> freq(max_ele + 1, 0);
    for (int i = 0; i < n; i++){
        freq[v[i]]++;
    }

    // creating cumulative freq
    for (int i = 1; i <= max_ele; i++){
        freq[i] += freq[i - 1];
    }

    // calculating a ans sorted array
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--){
        ans[--freq[v[i]]] = v[i];
    }

    // copy back the ans array to original array
    for (int i = 0; i < n; i++){
        v[i] = ans[i];
    }
}
int main(){

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    countSort(a);

    for (int i = 0; i < n; i++){
        cout << a[i] << " ";
    }cout << endl;

    return 0;
}