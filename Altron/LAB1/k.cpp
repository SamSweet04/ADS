#include <iostream>
#include <math.h>
#include <deque>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i ++){
        if (n % i == 0){
            cout << "composite" << endl;
            return 0;
        }
    }
    cout << "prime" << endl;
}
