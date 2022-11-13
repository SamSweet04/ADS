#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left;
    node *right;
    node(int _val){
        val = _val;
        left = right = 0;
    }
};

node *fix;

struct BST{
    BST(){
    root = 0;
}
    node * root;
    node * insert(node *cur, int val){
        if(cur == 0) return new node(val);
        if(val > cur->val)
             cur->right = insert(cur->right, val);
        if(val < cur->val) 
            cur->left =  insert(cur->left, val);
        return cur;
    }

    void print(node *cur){
        if(cur != 0){
            print(cur->left);
            cout << cur->val<< " ";
            print(cur->right);
        }
    }

    node* find(node *cur, int x){
        if(cur != 0){
            find(cur->left, x);
            if(cur->val == x) fix = cur;
            find(cur->right, x);
        }
    }

    int height(node *cur){
        if(cur == 0) return 0;
        return 1 + height(cur->left) + height(cur->right);
    }

    int height(int x){
    find(root, x);
    return height(fix);
}

    void insert(int val){
        root = insert(root, val);
    }

    void print(){
        print(root);
    }
};

int main(){
    BST bst;
    int n, x;
    cin >> n;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        bst.insert(t);
    }
    cin >> x;
    cout << bst.height(x);
    return 0;
} 