#include <bits/stdc++.h>
using namespace std;
struct Node{ 
    string s; 
    Node *next;  
    Node * prev;
    Node(){
        this-> next = NULL;
        this-> prev = NULL;
    }
    Node(string s){
        this->s = s; 
        this->next = NULL; 
}
    Node(string s, Node *next){
        this->s = s;
        this->next = next;
    }
};

struct LinkedList{
    int size = 0;
    Node *head;
    Node *tail;
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
    }
    void del(){
       head = head -> next;
    }
    void push_back(string s){
    Node * newNode = new Node(s);
    if(head == NULL){
        head = tail = newNode;
    }
    else{
        tail -> next = newNode;
        newNode -> prev = tail;
        tail = newNode;
    }
    }
    void print(){
    Node * cur = head;
    while(cur != NULL){
        cout << cur -> s << " ";
        cur = cur -> next;
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
