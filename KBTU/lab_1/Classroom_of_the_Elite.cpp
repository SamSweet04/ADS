#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    queue<int> s_cnt, k_cnt;
    for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'S') {
                s_cnt.push(i);
            } else {           // KSKS 
                                // 46
                                // 
                k_cnt.push(i);
            }
            }
    while (!s_cnt.empty() && !k_cnt.empty()) {
        if (s_cnt.front() < k_cnt.front()) {
            s_cnt.push(s_cnt.front() + s.size());
        } else {
            k_cnt.push(k_cnt.front() + s.size());
        }
        s_cnt.pop();
        k_cnt.pop();
    }
    cout << (!s_cnt.empty() ? "SAKAYANAGI" : "KATSURAGI");
}
