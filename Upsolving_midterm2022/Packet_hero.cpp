#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *right;
    Node *left;
    Node(int val){
        this->val = val;
        right = left = 0;
    }
};
struct BST{
private:
    Node *root;
    Node *push(Node *cur, int val){
        if(cur == 0) return new Node(val);
        if(val < cur-> val) cur->left = push(cur->left, val);
        if(val > cur-> val) cur->right = push(cur->right,val);
        return cur;
    }
    int count(Node *cur,int lvl){
        lvl++; 
        if(cur == 0) return 0;
        return (cur->val - lvl) + count(cur->left,lvl) + count(cur->right,lvl);
    }
public:
    BST(){
        root = 0;
    }
    void push(int val){
        root = push(root,val);
    }
    void count(){
        cout << count(root,-1);
 }
};

int main(){
    BST bst;
    int n; cin >> n;
    while(n--){
        int k;cin>> k;
        bst.push(k);
    }
    bst.count();
}