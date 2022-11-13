#include <iostream>
#include <math.h>

using namespace std;

int d[10005];



int sum(int a, int b){ 
    int ans = a + b;
    return ans;
}


int min(int a, int b, int c, int d){
    return min(min(a,b), min(c,d));
}

int fac(int n){
    int ans = 1;
    for (int i = 1; i <= n; i++){
        ans *= i;
    }
    return ans;
}

void Foo(int a[], int b[], int n){
    for (int i = 0; i < n; i ++){
        d[i] = abs(a[i] - b[i]);
    }
}

void print(int a[], int n){
    for (int i = 0; i < n; i ++){
        cout << a[i] << " ";
    }
}

bool isValid(string s, int n){
    for (int i = 0; i < s.size(); i ++){
        if (isdigit(s[i])){
            int j = i;
            int cnt = 0;
            while(isdigit(s[j]) && j < s.size()){
                j++;
                cnt++;
                if (cnt >= n){
                    return true;
                }
            }
        }
    }
    return false;
}


bool isValid1(string s, int n){
    int cnt = 0;
    for (int i = 0; i < s.size(); i ++){
        if (isdigit(s[i])){
            cnt++;
            if (cnt >= n) return true;
        }
        else{
            cnt = 0;
        }
    }
    return false;
}


int main() {
    string s;
    int n;
    cin >> s;
    cin >> n;
    if (isValid1(s, n)){
        cout << "Valid" << endl;
    }
    else{
        cout << "Not Valid" << endl;
    }

}
