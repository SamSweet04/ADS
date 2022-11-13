#include <bits/stdc++.h>
using namespace std;
struct Node{
    int k;
    int cnt;
    Node *next;
    Node(){
        this->k = 0;
        this->next = NULL;
        this->cnt = 0;
    }
    Node(int k){
        this->k = k;
        this->next = NULL;
        this->cnt = 0;
    }
};
struct LinkedList{
    Node *head;
    int max;
    LinkedList(){
        this->head = NULL;
        this->max = 0;
    }
    void push_back(int k){
        Node *tmp = new Node(k);
        if(this->head == NULL){
            this->head = tmp;
        }
        Node *cur = this->head;
        while(cur != NULL){
            if(cur->k == tmp->k){
                cur->cnt++;
                break;
            }
            if(cur->next == NULL){
                cur->next = tmp;
                break;
            }
            cur = cur->next;
    }
    }
     void search_max(){
        Node *cur = this->head;
        while(cur != NULL){
            if(cur->cnt > max)
                   max = cur->cnt;
            cur = cur->next;
        }
    }
     void print(){
        search_max();
        vector <int> vec;
        Node* cur = this->head;
        while(cur != NULL){
            if(cur->cnt == max) 
                 vec.push_back(cur->k);
            cur = cur->next;
        }
        sort(vec.rbegin(), vec.rend());
        for(auto i : vec){
            cout << i << " ";
        }
    }
};
    int main(){
    LinkedList *ll = new LinkedList();
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        ll->push_back(k);
    }
    ll->print();
}