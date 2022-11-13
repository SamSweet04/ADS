#include <bits/stdc++.h>
using namespace std;
int partition(int a[],int low, int high){
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i + 1;
}
void quickSort(int a[], int low,int high){
    if(low < high) {
        int pi = partition(a, low, pi - 1);
        quickSort(a, low, pi -1);
        quickSort(a,pi + 1, high);
    }
}
bool search(int a[], int l, int r, int x, vector<bool> &b){
    if(r == -1) return false;
    while(l < r){
        int mid = (l + r)/2;
        if(a[mid] >= x) r = mid;
        else l = mid;
    }
    while(!b[r] &&  a[r] == x && r < b.size() - 1) r++;
    if(a[r] == x && b[r]){
        b[r] = false;
        return true;
    }
    return false;
}
int main(){
    int n, m;
    cin >> n >> m;
    int a1[n], a2[m];
    vector<bool> b(m, true);
    for(int i = 0; i < n; i++) cin >> a1[i];
    for(int i = 0; i < m; i++) cin >> a2[i];
    quickSort(a1,0, n - 1);
    quickSort(a2, 0, m-1);
    for(int i = 0; i < n; i++){ 
        if(search(a2, -1, m-1, a1[i], b)) cout << a1[i] << " ";
    }
}