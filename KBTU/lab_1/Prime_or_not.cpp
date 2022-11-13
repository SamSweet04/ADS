#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    if(n > 1){
        for(int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    }
    else if(n >10e6 || n == 1){
        return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    stack <string> st; 
    if(isPrime(n)){
        st.push("YES");
    }
    else {
        st.push("NO");
    }
    cout << st.top();
}
