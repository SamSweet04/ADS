#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    stack <char> stack1;
    cin >> s;
    for (int i = 0; i < s.length(); i++) {
        if (!stack1.empty() && stack1.top() == s[i]){
                stack1.pop();
        }
        else{
            stack1.push(s[i]);
    }
    }
    cout << (stack1.empty() ? "YES" : "NO");
}