#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t, k = 0;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    cin >> t;
    for(int i = 0; i < a.size(); ++i){
        if(a[i] == t){
            cout << i + 1 << " ";
        }
    }
    return 0;
}