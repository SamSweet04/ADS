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

void Foo(int a[], int b[], int d[], int n){
    for (int i = 0; i < n; i++){
        d[i] = abs(a[i] - b[i]);
    }
}

void print(int a[], int n){
    for (int i = 0; i < n; i ++){
        cout << a[i] << " ";
    }
}

int main() {
    int n;
    cin >> n;
    int a[n];
    int b[n];
    int d[n];
    for (int i = 0; i < n; i ++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i ++){
        cin >> b[i];
    }
    Foo(a, b, d, n);
    print(d, n);
    return 0;
}
