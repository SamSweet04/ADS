#include <bits/stdc++.h>
using namespace std;
void print(deque <int> deq1){
    while(!deq1.empty()){
        cout << deq1.front() << " ";
        deq1.pop_front();
    }
    cout <<'\n';
}
void flushing(int k,deque <int> deq1){
    while(k>0){
        deq1.push_front(k);
        if(deq1.size() > 0){
            for(int i = 0; i < k; i++){
                deq1.push_front(deq1.back());
                deq1.pop_back();
            }
        }
        k--;
    }
    print(deq1);
}
int main(){
    int n,k;
    cin >> n;
    deque <int> deq1;
    while(n--){
        cin >> k;
        flushing(k,deq1);
    }
}