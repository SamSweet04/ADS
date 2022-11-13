#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
    long long getWorkTime(vector<ll> &islands, ll bucketSize){
        ll timeToWork = 0;
        for(auto &i : islands){
            timeToWork += i/ bucketSize;
            if(i % bucketSize) timeToWork++;
        }
        return timeToWork;
    }
    int main(){
        ll n,f;
        cin >> n >> f;
        vector <ll> islands(n);
        for(auto &island : islands){
            cin >> island;
        }
        ll left = 0,right = 1e18+123;
        while(left+1 < right){
            ll mid = (left+right) / 2;
            ll timeToSanta = getWorkTime(islands,mid);
            if(timeToSanta <= f) right = mid;
            else left = mid;
        }
        cout << right;
    }