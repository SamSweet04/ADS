#include <iostream>
using namespace std;

int find(int a[], int x, int l, int r){
    if(l > r) return -1;
    int m = l + (r-l)/2;
    if(a[m] == x) return m;
    else if(a[m] < x) return find(a, x, m+1, r);
    else return find(a, x, l, m-1);
}
int des_find(int a[], int x, int l, int r){
    int m = l + (r-l)/2;
    if(l > r) return -1;
    if(a[m] == x) return m;
    else if(a[m] > x) return des_find(a, x, m+1, r);
    else return des_find(a, x, l, m-1);
}
int main(){
    int t, n, m;
    cin >> t;
    int a[t];
    for(int i = 0; i < t; i++){
        cin >> a[i];
    }
    cin >> n >> m;
    int b[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }
    int k = 0;
    while(true){
        if(k == t) break;
        bool found = false;
        for(int i = 0; i < n; i++){
            int temp;
            if(i % 2 == 0) temp = des_find(b[i], a[k], 0, m-1);
            else temp = find(b[i], a[k], 0, m-1);
            if(temp != -1){
                found = true;
                cout << i <<  " " << temp;
                break;
            }
        }
        if(!found){
            cout << -1;
        }
        k++;
        cout << endl;
    }
    
    return 0;
}