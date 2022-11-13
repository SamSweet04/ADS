#include <bits/stdc++.h>
using namespace std;
int main(){
    deque<int> dq1, dq2;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        char s;
        int t;
        cin >> s;
        if(s=='+'){
            cin >> t;
            dq1.push_back(t);
        }
        if(dq1.size()>dq2.size()){
            dq2.push_back(dq1.front());
            dq1.pop_front();
        }
        if(s=='-'){
            cout << dq2.front() << endl;
            dq2.pop_front();
        }
        if(s=='*'){
            cin >> t;
            dq1.push_front(t);
        }
    }
}