#include <bits/stdc++.h>
using namespace std;

string  to_bin(long long k){
    string s = "";
    while(k != 0){

        s = char(k%2 + '0') + s;
        k /= 2;
    }
    return s;
}

int main(){
    deque<char> d;
    int n; cin >> n;
    while(n--){
        long long k; cin >> k;
       string s = to_bin(k);
       for(char i: s){
           if(i=='1' || d.empty()) d.push_back(i);
           else if(i == '0' && d.back() == '1') d.pop_back();
           else d.push_back(i);
       }
       if(d.empty()) cout << "YES \n";
       else {
           cout << "NO \n";
           d.clear();
       }
    }
    
    return 0;
}