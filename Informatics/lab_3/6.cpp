#include <iostream>
using namespace std;
int main(){
    int n;
    int a[1000],max,min;
    cin >> n >> a[0];
    max = a[0];
    min = a[0];
    for (int i = 1; i < n ;i++){
        cin >> a[i];
    }
    for (int i = 1; i < n ;i++){
        if(a[i] > max){
            max = a[i];
        }
        else if(a[i] < min){
            min = a[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(a[i] == max){
            a[i] = min;
        }
      cout << a[i] << " ";
    }