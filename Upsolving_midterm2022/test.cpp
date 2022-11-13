#include <bits/stdc++.h>
using namespace std;

string  to_bin(long long k){
    string s = "";
    while(k != 0){

        s = char(k%2 + '0') + s; // 2%2=="10"
        k /= 2;
    }
    cout << s << endl;
    return s;
}
int main(){
    int s;
    cin >> s;
    cout << to_bin(2);
}