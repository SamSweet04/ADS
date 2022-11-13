#include <iostream>
using namespace std;

unsigned gcd(unsigned a, unsigned b){
    if(b==0){
        return a;
    } else {
        return gcd(b, a%b);
    }
}
    unsigned lcm(unsigned a, unsigned b)
{
    return (b / gcd(a, b) ) * a;
}
 int main(){
    int t,cnt = 0;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        for(int j = 0; j < n; j++){
            int a = j;
            int b = j++;
            if(lcm(a,b)/gcd(a,b) < 3){
                cnt++;
                cout << cnt;
            };
        }
    }
 }