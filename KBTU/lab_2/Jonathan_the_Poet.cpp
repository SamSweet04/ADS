#include <bits/stdc++.h>
using namespace std;
struct Node{
    string s;
    Node *next;
    Node *prev;
    Node(){
        next = 0;
        prev = 0;
    }
    Node(string s){
        this->s = s;
        next = 0;
    }
};
struct LinkedList{
    int size = 0;
    Node *head;
    Node *tail;
    LinkedList(){
        head = 0;
        tail = 0;
    }
    void del(){
        head = head->next;
    }
    void push_back(string s){
        Node *tmp = new Node(s);
        if(head == 0){
            head = tail = tmp;
        }
        else{
            tail->next = tmp;
            tmp -> prev = tail;
            tail = tmp;
        }
    }
    void print(){
        Node *cur = head;
        while(cur != 0){
            cout << cur -> s << " ";
            cur = cur-> next;
        }
    }
};
int main(){
    LinkedList *ll = new LinkedList();
    int n, k;
    cin >> n >> k;
    while(n--){
        string s;
        cin >> s;
        ll->push_back(s);
    }
    while(k--){
        ll->push_back(ll->head->s);
        ll->del();
    }
    ll->print();
}