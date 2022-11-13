#include <bits/stdc++.h>
using namespace std;
int main(){
    deque <int> deq1,deq2;
    int n,counter = 0;
    for(int i = 0; i < 5; i++){
        cin >> n;
        deq1.push_back(n);
    }
    for(int i = 0; i < 5; i++){
        cin >> n;
        deq2.push_back(n);
    }
    while(!deq1.empty() && !deq2.empty()){
        if(counter > 10e6){
            cout << "blin nichya";
            break;
        }
        else if(deq1.front() == 9 && deq2.front() == 0){
            deq2.push_back(deq1.front());
            deq2.push_back(deq2.front());
            deq1.pop_front();
            deq2.pop_front();
        }
        else if(deq1.front() == 0 && deq2.front() == 9){
            deq1.push_back(deq1.front());
            deq1.push_back(deq2.front());
            deq1.pop_front();
            deq2.pop_front();
        }
        else if(deq1.front()>deq2.front()){
            deq1.push_back(deq1.front());
            deq1.push_back(deq2.front());
            deq1.pop_front();
            deq2.pop_front();
        }
        else if(deq1.front()< deq2.front()){
            deq2.push_back(deq1.front());
            deq2.push_back(deq2.front());
            deq1.pop_front();
            deq2.pop_front();
        }
    counter+=1;
    }
    if(deq1.empty()) cout << "Nursik" <<" "<< counter;
    else cout << "Boris" <<" "<< counter;
}