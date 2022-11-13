#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<string> q1, q2, q3;
    int n;
    string str;
    while(cin >> n){
        if(n==9){
        cin >> str;
        q1.push(str);
        }
        if(n==10){
            cin >> str;
            q2.push(str);
        }
        if(n==11){
            cin >> str;
            q3.push(str);
        }
    }
    while(!q1.empty()){
        cout << "9 " << q1.front() << endl;
        q1.pop();
    }
    while(!q2.empty()){
        cout << "10 " << q2.front() << endl;
        q2.pop();
    }
    while(!q3.empty()){
        cout << "11 " << q3.front() << endl;
        q3.pop();
    }
} 