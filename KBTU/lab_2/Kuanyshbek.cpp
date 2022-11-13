#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node *next;
    int val;
    Node(){
        next = 0;
        val = 0;
    }
    Node(int val){
        next = 0;
        this->val = val;
    }
};
struct LinkedList{
     Node *tail;
     Node *head;
     LinkedList(){
        tail = 0;
        head = 0;
     }
    void push_back(int k){
        Node *tmp = new Node(k);
        if(head == 0){
            head = tmp;
            tail = tmp;
        }
        else{
            tail->next = tmp;
            tail = tmp;
        }
    }

    void del(int index){
        Node *cur = head;
        for(int i = 0; i <= index - 1; i++){
            cur = cur->next;
        }
        cur->next = cur->next->next;
    }
    
    void print(){
        Node *tmp = head;
        while(tmp != 0){
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
    }    
};

    int main(){
        LinkedList *ll = new LinkedList();
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            if(i%2==0){
                ll->push_back(x);
            }
        }
        ll->print();

    }