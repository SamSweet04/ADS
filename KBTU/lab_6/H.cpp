#include<bits/stdc++.h>

using namespace std;

int partition(char a[], int low, int high){
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(a[j] < pivot){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quickSort(char a[], int low, int high){
    if(low < high){
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int index(char a[], int l, int r, char k){
    while(l + 1 < r){ 
        int mid = (l + r) / 2;
        if(a[mid] <= k){
            l = mid;
        }
        else r = mid;
    }
    return l; 
}

int main(){
    int n; scanf("%d",&n);
    char a[n+1];
    for(int i = 0; i < n; i++) scanf("%d",&a[i]); 
    char k; scanf("%d",&k);
    a[n] = k; // a[3] = a
    quickSort(a, 0, n); // a c f g // c f f j
    n++; // 4 
    int ind = index(a, 0, n, k) + 1 ; // index(a, l = 0, r = 4, k = 'a') 
    (ind == n) ? cout << a[0] : cout << a[ind]; // (1 == 4) cout << a[1] == c; 
}

