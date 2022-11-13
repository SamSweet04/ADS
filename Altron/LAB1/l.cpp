#include <iostream>
using namespace std;
int great_common(int a, int b){
    if(b==0){
        return a;
    } else {
        return great_common(b, a%b);
    }
}
int least_common(long long a, long long b){
    return (a*b)/great_common(a, b);
}

int main(){
    long long i, j;
    cin >> i >> j;
    cout << least_common(i, j);
}