#include <iostream>

using namespace std;
int summ(int target, int a, int b, int c){
    return target/a + target / b + target / c;
}
int main(){
    int n;
    cin>>n;
    int a,b,c;
    cin>>a>>b>>c;
    int l = 0;
    int r = 1e9;
    while(l <= r){
        int mid = l + (r-l)/2;
        int temp = summ(mid, a, b ,c);

        if(temp < n){
            l = mid+1;
        }
        else{
            r = mid-1;
        }

    }
    cout<<r + 1;
}