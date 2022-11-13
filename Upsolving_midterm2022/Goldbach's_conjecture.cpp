#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
bool isPrime(ll n) {
	if (n == 1 || n == 0) {
		return false;
	}
	for (ll i = 2; i <= ll(sqrt(n)); i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	ll n,cnt = 0;
	cin >> n;
	ll i = 2;
    ll j = n - 2;
	while (true) {
            //  if(n % i == 0){
            //      cnt++;
            cout << cnt;
   // }
		i++;
        j--;
}
    cout << cnt;
    }