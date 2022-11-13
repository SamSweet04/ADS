#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int bin_search(int prefSum[],int x,int n){
    int left = -1;
    int right = n-1;
    while(left + 1 < right){
        int mid = (left + right) / 2;
        if(prefSum[mid] >= x) right = mid;
        else left = mid;
    }
    return right+1;
}
int main(){
    int n, mistake;
    cin >> n >> mistake;
    int prefSum[n];
    for(int i = 0; i < n; i++){
        cin >> prefSum[i];
        if(i == true)
            prefSum[i] += prefSum[i-1];
    }
    int findMistake;
    for(int j = 0; j < mistake;j++){
        cin >> findMistake;
        cout << bin_search(prefSum,findMistake,n) << endl;
}
}