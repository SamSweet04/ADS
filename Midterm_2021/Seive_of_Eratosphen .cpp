// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>
using namespace std;
 
void SieveOfEratosthenes(int n)
{

    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    vector<int> v;
    int cnt;
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }

    }

    for (int p = 2; p <= n; p++){
        if(prime[p])  v.push_back(p);
    }
    for(int i = 0; i < v.size();i++){
        if(v[i+1] - v[i] == 2) cnt++;
    }
    cout << cnt;
}

int main()
{
    int n = 10;
    SieveOfEratosthenes(n);
    return 0;
}
