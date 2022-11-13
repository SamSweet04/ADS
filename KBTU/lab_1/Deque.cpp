#include <bits/stdc++.h>
using namespace std;
int main(){
    deque <int> deq1;
    char c;
    int n,a,b;
    while(cin >> c){
        if(c == '!') break;
        if(c == '+'){
            cin >> n;
            deq1.push_front(n);
        }
        if(c == '-'){
            cin >> n;
            deq1.push_back(n);
        }
        if(c == '*'){
            if(deq1.size()>=2){
                cout << deq1.front()+deq1.back() << endl;
                deq1.pop_back();
                deq1.pop_front();
            }
            else if(deq1.size() == 1){
                cout << deq1.front()*2 << endl;
                deq1.pop_front();
            }
            else{
                cout << "error" << endl;
            }
        }
    }
    

}