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

Node* temp;

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
    // Node * printSubtree(bool ok, int k, Node * cur){
    // if(cur != nullptr){
    //     if(cur -> val == k) ok = true;
    //     if(ok) cout << cur -> val << " ";
    //     printSubtree(ok, k, cur -> left);
    //     printSubtree(ok, k, cur -> right);
    // }   
    Node *subtree(Node *cur, int x){
        if(cur != nullptr){
            subtree(cur->left, x);
            if(cur->val == x) temp = cur;
            subtree(cur->right, x);
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
        subtree(root, x);
        print(temp);
    }
//     void printSubtree(int k){
//     printSubtree(false, k, root);
// }
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
    // int k; cin >> k;
    // tree.printSubtree(k);
} 