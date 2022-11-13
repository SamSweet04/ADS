#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int val){
        this->val = val;
        left = right = nullptr;
    }
};

Node* fix;

class BST{
private:
    Node * root;
    Node * push(Node *cur, int val){
        if(cur == nullptr) return new Node(val);
        if(val > cur->val) cur->right = push(cur->right, val);
        if(val < cur->val) cur->left = push(cur->left, val);
        return cur;
    }

    void print(Node *cur){
        if(cur != nullptr){
            cout << cur->val << " ";
            print(cur->left);
            print(cur->right);
        }
    }

    Node *find(Node *cur, int x){
        if(cur != nullptr){
            find(cur->left, x);
            if(cur->val == x) fix = cur;
            find(cur->right, x);
        }
    }

public:
    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }
    void print(int x){
        find(root, x);
        print(fix);
    }
};



int main(){
    BST tree;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        tree.push(t);
    }
    cin >> x;
    tree.print(x);
    return 0;
} 