#include <bits/stdc++.h>
using namespace std;
int max_distance = 0;
struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int val){
        this->val = val;
        left = right = nullptr;
    }
};

class BST{
private:
    Node * root;
    Node * push(Node *cur, int val){
        if(cur == nullptr) return new Node(val);
        if(val > cur->val) cur->right = push(cur->right, val);
        if(val < cur->val) cur->left = push(cur->left, val);
        return cur;
    }

    int height(Node * cur){
        if(cur == nullptr) return 0;
        return 1 + max(height(cur->left), height(cur->right));
    }

    void find(Node * cur){
        if(cur != nullptr){
            if(height(cur->left)+height(cur->right)+1 > max_distance ) max_distance = height(cur->left)+height(cur->right)+1; 
            find(cur->left);
            find(cur->right);
        }
    }

public:
    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }
    void find(){
        find(root);
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
    tree.find();
    cout << max_distance;
    return 0;
} 