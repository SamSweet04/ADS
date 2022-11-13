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
    Node* head;
    Node *tail;
    int size = 0;
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
        else{
            this->tail->next = tmp;
            this->tail = tmp;
        }
        size++;
    }
    
void insert(int pos, int num){
    Node* newNode = new Node(num);
    if(pos == 0){
        newNode->next = head;
        head = newNode;
    }
    Node* cur = head;
    int cnt = 0;
    while(cur != nullptr){
        if(cnt == pos-1){
            newNode->next = cur->next;
            cur->next = newNode;
            break;
        }
        cnt++;
        cur = cur->next;
    }
}
    void print(){
        Node* cur = head;
        while(cur != nullptr){
            cout << cur->k << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};
int main(){
    LinkedList *ll = new LinkedList();
    int n, num, pos;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        ll->push_back(x);
    }
    cin >> num >> pos;
    ll->insert(pos, num);
    ll->print();
}