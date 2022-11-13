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

class BST{
private:
    int sum = 0;
    Node * root;
    Node * push(Node *cur, int val){
        if(cur == nullptr) return new Node(val);
        if(val > cur->val) cur->right = push(cur->right, val);
        if(val < cur->val) cur->left = push(cur->left, val);
        return cur;
    }

    void print(Node *cur, int lvl){
        if(cur != nullptr){
            if(lvl == 0){
                sum+=cur->val;
            }
            else{
                print(cur-> left, lvl - 1);
                print(cur -> right, lvl - 1);
            }
        }
        else{
            return;
        }
    }
     int height(Node * cur){
        if (cur == nullptr) return 0;
        return max(height(cur -> left), height(cur -> right)) + 1;
    }




public:
    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }
    void print(){
        int hght = height();
        cout << hght << endl;
        for(int i = 0; i < hght; i++){
            print(root,i);
            cout << sum << " ";
            sum = 0;
        }
    }

    int height(){
        return height(root);
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
    tree.print();
    return 0;
} 