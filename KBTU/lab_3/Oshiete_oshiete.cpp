#include<iostream>
typedef long long ll;
using namespace std;

int n,k,a[100001];
ll cnt = 0,sum = 0;

bool checkForSum(int a[], int n, ll x, int k){
    cnt = 0;
    sum = 0;
    for (int i = 0; i < n; i++){
        if (a[i] > x) return false;
        else if (sum+a[i] > x){
            sum = a[i];
            cnt++;
        }
        else sum += a[i];    
    }
    cnt++;
    return cnt <= k;
}

int main(){
    cin >> n >> k;
    ll left=0,right=0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        right += a[i];
    }
    ll ans = 0;
    while(left <= right){
        ll mid = (left+right)/2;
        if (checkForSum(a,n,mid,k)){
            ans = mid;
            right = mid-1;
        }
        else left = mid+1;
    }
    cout << ans;
}