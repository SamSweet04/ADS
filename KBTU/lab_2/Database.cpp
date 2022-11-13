#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node *next;
    string s;
    Node(){
        next = 0;
    }
    Node(string s,Node *next){
        this->next = next;
        this->s = s;
    }
};

struct LinkedList{
    Node *head;
    int cnt = 0;
    LinkedList(){
        head = 0;
    }
    void push_back(string s){
        if(head == 0){
            Node *tmp = new Node(s,0);
            head = tmp;
            cnt++;
        }
        else if(head->s!=s){
             Node *tmp = new Node(s,head);
             head = tmp;
             cnt++;
        }
    }

    void print(){
        cout<<"All in all: "<< cnt;
        cout<<"\nStudents:\n";  
        Node *cur = head;
        while(cur != 0){
            cout << cur->s << endl;
            cur = cur->next;   
        }
    }

};

int main(){
    LinkedList *ll=new LinkedList();
    int n;
    string s;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> s;
        ll->push_back(s);
    }
    ll->print();
}