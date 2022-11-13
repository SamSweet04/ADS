#include <bits/stdc++.h>
#include <list>
using namespace std;
int main(){
    string s1;
    string s2;
    cin >> s1 >> s2;
    deque <char> deq1;
    deque <char> deq2;;
    for(int i = 0; i < s1.size();i++){
        if(deq1.empty()){
            if(s1[i] >= 'a' && s1[i] <= 'z'){
                 deq1.push_back(s1[i]);
        }
        }
        else{
            if(s1[i] == '#'){
                  deq1.pop_back();
            }
            else{
                deq1.push_back(s1[i]);
            }
        }
    }
     for(int i = 0; i < s2.size();i++){
        if(deq2.empty()){
            if(s2[i] >= 'a' && s2[i] <= 'z'){
                deq2.push_back(s2[i]);
        }
        }
        else{
            if(s2[i] == '#'){
                  deq2.pop_back();
            }
            else{
                deq2.push_back(s2[i]);
            }
        }
     }
     if(deq1.size()==deq2.size()){
        cout << "Yes" << endl;

     }
     else{
        cout << "No" << endl;
     }
}