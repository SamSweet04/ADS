#include <iostream>
using namespace std;
int n,m;
bool binIteration(int a[], int x){
    int l = 0, r = n - 1;

    while(l <= r){
        int mid = l + (r - l) / 2;
        if(a[mid] == x) return true;
        else if(a[mid] > x) r = mid-1;
        else l = mid + 1;
    }
    return false;
}

int main(){
    cin>>n>>m;
    int a[n], b[m];
    for(int i = 0; i < n;i++){
        cin>>a[i];
    }
    for(int j = 0 ; j < m ; j++){
        cin>>b[j];
    }
    for(int j = 0; j < m; j++){
        for (int i = 0 ; i < n ; i++){
            if(binIteration(a, b[j])){
                for(int i = 0 ; i < n; i++){
                    if(a[i] == b[j]){
                        cout<<i+1<<" ";
                        break;
                    }
                }
                for(int i = n-1; i>=0; i--){
                    if(a[i] == b[j]){
                        cout<<i+1<<endl;
                        break;
                    }
                }
            }
            else{
                cout<<0<<endl;
            }
            break;
        }
    }

}