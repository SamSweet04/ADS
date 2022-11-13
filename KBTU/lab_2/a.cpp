#include <bits/stdc++.h>
using namespace std;
struct Node{ 
    int val; 
    Node *next;  
    Node(){
        this->val = 0;
        this->next = NULL;
    }
    Node(int val){
        this->val = val; 
        this->next = NULL; 
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
    void push_back(int val){
        if(size == 0){
            push_front(val);
            return;
        }
        Node *tmp = new Node(val);
        this->tail->next = tmp;
        this->tail = tmp;
        size+=1;
    }
    void push_front(int val){
        Node *tmp = new Node(val);    
        if(size == 0 ){
            this->tail = tmp;
            this->head = tmp; 
        }
        this->head = tmp;
        size+=1;
    }
    int get_nearest(int k){
        Node *cur = this->head;
        int min = abs(k - cur-> val), offset = 0, i = 0;
        while(cur){
            if((abs(k-cur->val)<min)){
                min = abs(k - cur-> val);
                offset = i;
        }
            cur = cur -> next;
            i++;
        }        
        return offset;
    }
};

int main(){
    LinkedList *ll = new LinkedList(); 
    int n,l;
    cin >> n;
    while(n--){
        int a;
        cin >> a;
        ll -> push_back(a);
    }
    cin >> l;
    cout << ll->get_nearest(l) << endl;
    return 0;
}