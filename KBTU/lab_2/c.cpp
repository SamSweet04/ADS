#include <bits/stdc++.h>
using namespace std;
struct Node{
    int k;
    Node *next;
    Node(){
        this->k = 0;
        this->next = NULL;
    }
    Node(int k){
        this->k = k;
        this->next = NULL;
    }
};
struct LinkedList{
    Node *head;
    Node *tail;
    LinkedList(){
        this->head = NULL;
        this->tail = NULL;
    }
    void push_back(int k){
        Node *tmp = new Node(k);
        if(this->head == NULL){
            this->head = tmp;
            this->tail = tmp;
        }
        else {
            this->tail->next = tmp;
            this->tail = tmp;
        }
    }
    void del(){
        Node *cur = this->head;
        while(cur != NULL && cur->next != NULL){
            Node *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
            cur = cur->next;
        }
    }
    void print(){
        Node *cur = this->head;
        while(cur != NULL){
            cout << cur -> k << " ";
            cur = cur -> next;
        }
        cout << '\n';
    }
};
int main() {
    LinkedList *ll = new LinkedList();
    int n, k;
    cin >> n;
    while(n--){
        cin >> k;
        ll->push_back(k);
    }
    ll->del();
    ll->print();
}