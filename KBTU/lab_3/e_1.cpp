#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int n , k;
    cin >> n >> k;
    int a[n][4];
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < 4; j++){
            cin >> a[i][j];
    }
    }
    int l = 1;
    int r = pow(10,9);
    int ans = pow(10,9);
    while(l <= r){
        int mid = l + (r - l) / 2;
        int cnt= 0;
        for(int i = 0; i < n; i++){
            if(a[i][0] <= mid && a[i][1] <= mid && a[i][2] <= mid && a[i][3] <= mid) cnt++;
            if(cnt < k) l = mid + 1;
            else{
                ans = min(ans,mid);
                r = mid - 1;
            }
            cout << ans << endl;
        }
    }
}

#include <bits/stdc++.h>

using namespace std;

struct Pasture{
    int x1, x2;
    int y1, y2;
};

int getPasturesCount(vector<Pasture> &pastures, int x) {
    int res = 0;
    for(auto &pasture : pastures) {
        if(pasture.x1 <= x && pasture.y1 <= x && pasture.x2 <= x && pasture.y2 <= x)
            res++;
    }
    return res;
}

int main() {

    int n, k;
    cin >> n >> k;

    vector<Pasture> pastures(n);
    for(auto &pasture : pastures) {
        cin >> pasture.x1 >> pasture.y1 >> pasture.x2 >> pasture.y2;
    }

    int l = 0, r = 1e9+2;

    while(l + 1 < r) {
        int mid = (l+r)/2;
        if(getPasturesCount(pastures, mid) >= k)
            r = mid;
        else
            l = mid;
    }

    cout << r;

    return 0;
}


