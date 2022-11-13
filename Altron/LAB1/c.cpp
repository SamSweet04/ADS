#include <iostream>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main() {
    deque<int> st;
    string s = "";
    while(s != "exit"){
        cin >> s;
        if (s == "push_front"){
            int n;
            cin >> n;
            st.push_front(n);
            cout << "ok" << endl;
        }
        if (s == "push_back"){
            int n;
            cin >> n;
            st.push_back(n);
            cout << "ok" << endl;
        }
        if (s == "pop_front"){
            cout << st.front() << endl;
            st.pop_front();
        }
        if (s == "pop_back"){
            cout << st.back() << endl;
            st.pop_back();
        }
        if (s == "front"){
            cout << st.front() << endl;
        }
        if (s == "back"){
            cout << st.back() << endl;
        }
        if (s == "size"){
            cout << st.size() << endl;
        }
        if (s == "clear"){
            while (!st.empty()){
                st.pop_front();
            }
            cout << "ok" << endl;
        }
    }
    cout << "bye" << endl;
    return 0;
}
