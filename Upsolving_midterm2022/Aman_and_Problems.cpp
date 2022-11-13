#include <bits/stdc++.h>
using namespace std;

void binSearch(int arr[], int size, int k){
    int l = size/2, r = size/2 + 1;
    // cout << l << r << endl;
    while(true){
        int s = arr[l] + arr[r];
        if(s == k && l != r){
            // cout << s << l << r << endl;
            cout << arr[l] << " " << arr[r];
            return;
        } 
        // cout << s << l << r <<"first" << endl;
        if(s > k) l--;
        else r++;
    }
}

int main(){
    int n, k; cin >> k >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    binSearch(arr, n-1, k);
    
    return 0;
}