#include <iostream>

using namespace std;


int sum(int a, int b){
    int ans = a + b;
    return ans;
}


int min(int a, int b, int c, int d){
    return min(min(a, b), min(c,d));
}

int fac(int n){
    int ans = 1;
    for (int i = 1; i <= n; i ++){
        ans *= i;
    }
    return ans;
}

int main() {
    cout << fac(5) << endl;
    cout << sum(1, 2) << endl;
    cout << min(5, 4, 3, 2) << endl;
    return 0;
}
