#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* prev;
    node* next;
    node(int val){
        this->val = val;
        next = prev = nullptr;
    }
};

struct linkedlist{
    node* head;
    node* tail;
    bool reversed;
    linkedlist(){
        head = tail = nullptr;
        reversed = false;
    }
    void addBack(int val){
        node* newnode = new node(val);
        if(!head && !tail) head = tail = newnode;
        else{
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
    }
    void addFront(int val){
        node* newnode = new node(val);
        if(!head && !tail) head = tail = newnode;
        else {
            head->prev = newnode;
            newnode->next = head;
            head = newnode;
        }
    }
    void printFromFront(){
        node* temp = head;
        while(temp){
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
    void printFromBack(){
        node* temp = tail;
        while(temp){
            cout << temp->val << " ";
            temp = temp->prev;
        }
    }
    void reverse(){
        reversed = !reversed;
    }
    void add(int val){
        if(reversed) addFront(val);
        else addBack(val);
    }
    void print(){
        if(!reversed) printFromFront();
        else printFromBack();
    }
};


int main(){
    linkedlist * leo = new linkedlist();
    int n; cin >> n;
    while(n--){
        int c; cin >> c;
        if(c == 1){
            int val; cin >> val;
            leo->add(val);
        }
        else leo->reverse();
    }
    leo->print();
    
    return 0;
}