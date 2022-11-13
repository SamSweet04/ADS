#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    stack <int> st; 
    int cnt = 0,i = 2, pr;
    while(cnt < n) {
        if (isPrime(i)) {
            pr = i;
            cnt++;
        }
        i++;
        st.push(pr);
    }

    cout << st.top();
}
