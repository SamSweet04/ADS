#include <iostream>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    int max = -2147483648;
    int ind;
    for(int i = 1;i <= n;i++){
        if(a[i] > max){
            max = a[i];
            ind = i;
        }
    }
    cout << ind;
    return 0;
}