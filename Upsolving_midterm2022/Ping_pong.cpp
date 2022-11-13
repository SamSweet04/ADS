#include <iostream>
#include <deque>

using namespace std;

int main() {
    int n, x;
    cin >> n;
    deque<int> q;
    while(n--){
        cin >> x; q.push_back(x);
        if(x >= 3000){ // 15000 >= 3000
            int diff = x - 3000; // diff = 12000
            while(!q.empty() && q.front() < diff){ // while(yes && 3000 < 12000) == no
                q.pop_front();
            }
        }
        cout << q.size() << " ";
    }
}
// 4
// 1 3 3000 3002

// 1 2 3 3