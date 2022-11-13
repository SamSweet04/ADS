#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

// int getCompetitor(vector <int> &competitors, int power){
//     if(power < competitors[0]) return -1;
//     int l = 0,r= competitors.size();
//     while(l + 1 < r){
//         int mid = (l+r)/2;
//         if(competitors[mid] <= power)
//                 l = mid;
//         else{
//              r = mid;
//             }
//     }
//              return l;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector <int> competitors(n);
//     vector <int> prefSum(n);
//     for(int &i : competitors) cin >> i;
//     sort(competitors.begin(),competitors.end());
//     prefSum[0] = competitors[0];
//     for(int i = 1; i < n; i++){
//         prefSum[i] = competitors[i] + prefSum[i-1];
//     }
//     int tests;
//     cin >> tests;
//     while(tests--){
//         int power;
//         cin >> power;
//         int id = getCompetitor(competitors,power);
//         cout << (id != -1 ? id+1: 0) << " " << (id != -1 ? prefSum[id] : 0) << endl;
//     }
// }

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(),v.end());
    int round; cin >> round;
    for(int i = 1; i <= round;i++){
        ll sum = 0;
        int ind = 0;
        int power;
        cin >> power;
        for(int j = 0; j < v.size(); j++){
            if(power >= v[j]) {sum+=v[j];
            ind = j;}
        }
        cout << ind+1 << " " << sum << endl;
    }

}
