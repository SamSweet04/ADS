#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node *next;
    int n;
    Node(){
        next = 0;
    }
    Node(int n){
        next = 0;
        this->n = n;
    }
};

struct LinkedList{
    Node *head;
    int pos = 0;
    LinkedList(){
        head = 0;
    }
    void push_back(int n,int ind){
        if(head == 0){
            Node *tmp = new Node(n);
            head = tmp;
            pos++;
        }
        else if(pos++ == ind ){

             
        }
    }

    void print(){
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