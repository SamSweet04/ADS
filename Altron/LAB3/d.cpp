#include <iostream>
#include <algorithm>
using namespace std;

int binSearach(int a[], int l, int r,int max){
    max = a[r];
    return max;
}
int main(){
    int n; cin >> n;
    int a[n];
    int max = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    cout << binSearach(a, 0, n-1, max);
    return 0;
}