#include <iostream>
using namespace std;


// int numOfSafes(int k){

// }

bool isCool(int n){
    int cnt;
    for(int i = 2 ; i <= n/2+1; i++){
        if(cnt > 2){
            return false;
        }
        if(n % i == 0){
            if(i*i == n){
                cnt++;
            }
            cnt++;
        }
    }
    if(cnt == 2) return true;
    return false;
}
int main(){
    int n;
    cin>>n;
    // isCool(n)? cout<<"YES" : cout<<"NO";
    int s = 0;
    for(int i = 3; i <= n ; i++){
        if(isCool(i)){
            s++;

        }
        cout<<"";
    }
    cout<<s;
}