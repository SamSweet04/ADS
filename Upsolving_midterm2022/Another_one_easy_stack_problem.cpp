#include <bits/stdc++.h>
using namespace std;
int main(){
vector <int> st;
    int n; cin >> n;
    for(int i = 0; i < n ; i++){
        string s;
        cin >> s;
        if(s == "add"){
            int k;
            cin >> k;
            st.push_back(k);
            // �������� � ����
        }
        if(s == "delete"){
            if(st.empty()){
                continue;
            }
            else st.pop_back();
            // ������� �� �����
        }
        if(s == "getmax"){
            if(st.empty()) {cout << "error" << endl;
            continue;}
            int max = INT_MIN;
            for(int i = 0; i < st.size(); i++){
                if(max < st[i])  max = st[i];
            }
            cout << max << endl;
             //�������� �������� � ��������
        }
        if(s == "getcur"){ 
            if(st.empty()) {cout << "error" << endl;
            continue;}
            else{
                cout << st.back() << endl;
            }
            // �������� �������  � ��������
        }
    }
}