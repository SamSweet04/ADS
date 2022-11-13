#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
    if (n > 1){
        for(int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0)
                return false;
        }
    }
    else{
        return false;
    }
    return true;
}

int main() {
    int n;
    stack <int> st;
    cin >> n;
    int i = 2,cnt = 0, pr = 0, pr_2 = 0;
    while(pr_2 < n){
        if (isPrime(i)) {
            cnt++;
            if (isPrime(cnt)) {
                pr = i;
                pr_2++;
            }
        }
        i++;
        st.push(pr);
    }
    cout << st.top();
}
