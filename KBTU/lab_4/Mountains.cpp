#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node *left;
    Node *right;
    Node(int val){
        this-> val = val;
        left = right = nullptr;
    }
};
class BST{
private:
     Node *root;
     Node *push(Node *cur, int val){
        if(cur == 0){
            return new Node(val);
        }
        if(val < cur->val) cur->left = push(cur->left,val);
        if(val > cur->val) cur->right = push(cur->right,val);
        return cur;
     }

        bool hasPath(string s,Node *cur, int pos){
            if(cur == nullptr) return false;
            if(pos == s.size()) return true;
            if(s[pos] == 'L') return hasPath(s,cur->left,pos+1);
            else return hasPath(s,cur->right,pos+1);
     }

public: 
    BST(){
        root = nullptr;
    }
    void push(int val){
        root = push(root, val);
    }
    Node *getRoot(){
        return root;
    }
    bool hasPath(string s){
        return hasPath(s,root,0);
    }
};
int main(){
    BST tree;
    string s;
    int n,m;
    cin >> n >> m;
    int k;
    for(int i = 0; i < n;i++){
        cin >> k;
        tree.push(k);
}  
    for(int i = 0; i < m; i++){
        Node *cur = tree.getRoot();
        bool exist = true;
        cin >> s;
        // if(tree.hasPath(s)) cout <<  "YES" << endl;
        // else cout << "NO" << endl;
        for(int i = 0; i < s.size();i++){
        if(s[i] == 'L')
            cur = cur -> left;    
        if(s[i] == 'R')
            cur = cur->right;
        if(cur == 0){
           exist = false;
           break;
        }
        
    }
     cout << (exist ? "YES" : "NO") << endl;
    }
 }
