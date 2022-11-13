#include <iostream>
#include <vector>
using namespace std;
bool error = false;
struct Node{
    string val;
    Node* next;
    Node(string val){
        this->val = val;
        next = nullptr;
    }
};

class Linkedlist{
    Node *head;
public:
    int size = 0;
    Linkedlist(){
        head = nullptr;
    }


    void print(){
        if(size == 0){
            cout << "EMPTY" << endl;
        }
        else{
            Node *cur = head;
            while(cur != nullptr){
                cout << cur->val << endl;
                cur = cur->next;
            }
        }
    }
    void push(string s, int pos){
        Node* newNode = new Node(s);
        if(pos == 1){
            if(head == nullptr){
                head = newNode;
                size++;
                return;
            }
            newNode->next = head;
            head = newNode;
            size++;
            return;
        }
        Node *cur = head;
        int cnt = 0;
        while(cur != nullptr){
            cnt += 1;
            if(cnt+1 == pos){
                newNode->next = cur->next;
                cur->next = newNode;
            }
            cur = cur->next;
        }
        size++;
    }

    void del(int pos){
        Node *cur = head;
        int cnt = 0;
        if(pos == 1){
            head = head->next;
            size--;
            return;
        }
        while(cur != nullptr){
            cnt += 1;
            if(cnt+1 == pos){
                cur->next = cur->next->next;
            }
            cur = cur->next;
        }
        size--;
    }

    void replace(int pos, string s){
        Node *newNode = new Node(s);
        Node *cur = head;
        int cnt = 0;
        if(pos == 1){
            newNode->next = head->next;
            head = newNode;
            return;
        }
        while(cur != nullptr){
            cnt += 1;
            if(cnt+1 == pos){
                newNode->next = cur->next->next;
                cur->next = newNode;
            }
            cur = cur->next;
        }
    }
};
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    Linkedlist list;
    char z;
    int n;

    while(cin >> z >> n){
        getline(cin, s);
        s.erase(0, 1);
        if(z == '+'){
            if(list.size + 1 < n){
                cout << "ERROR";
                return 0;
            }
            list.push(s, n);
        }
        else if(z == '-'){
            if(list.size < n){
                cout << "ERROR";
                return 0;
            }
            list.del(n);
        }
        else{
            if(list.size < n){
                cout << "ERROR";
                return 0;
            }
            list.replace(n, s);
        }
    }

    list.print();

    return 0;
}