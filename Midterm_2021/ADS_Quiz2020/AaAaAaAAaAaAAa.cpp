#include <iostream>
using namespace std;

struct Node{
    int val;
    Node * next;
    Node(int val){
        this->val = val;
        next = nullptr;
    }
};
class LinkedList{
    Node * head;
public:
    LinkedList(){
        head =nullptr;
    }
    void push(int val){
        if(!head){
            head = new Node(val);
            return;
        }
        Node * cur = head;
        while(cur){
            if(!cur->next){
                cur->next = new Node(val);
                break;
            }
            cur = cur->next;
        }

        
    }

    void reversePro(){
        Node * next = nullptr;
        Node * prev = nullptr;
        Node * cur = head;

        while(cur){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
    
    void print(){
        Node * cur = head;
        while(cur){
            cout<<cur->val<<" ";
            cur = cur->next;
        }
        cout<<endl;
    }
};
int main(){
    LinkedList ll;
    int n;
    cin>>n;
    while(n--){
        int k;
        cin>>k;
        if(k == 1){
            int x;
            cin>>x;
            ll.push(x);
        }
        else ll.reversePro();
    }
    ll.print();
}