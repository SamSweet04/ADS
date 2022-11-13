#include<bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    Node *right;
    Node *left;
    Node(int val){
        this->val = val;
        left = right = 0;
    }
};
struct BST{
private:
    Node *root;
    int cnt = 0;
    Node *push(Node *cur,int val, int z){
    if(cur == 0) return new Node(val);
    if(z == 1) cur->right = push(cur->right,val,z);
    if(z == 0) cur->left = push(cur->left,val,z);
    return cur;
}
    Node *push2(Node *cur,int val,int son, int z){
        if(cur != 0){
            if(cur->val == val) return push(cur,son,z);
            push2(cur->right,val,son,z);
            push2(cur->left,val,son,z);
        }
    }
    int height(Node *cur){
        if(cur == 0) return 0;
        return max(height(cur->left),height(cur->right))+1;
    }
    void levels(Node *cur,int lvl){
        if (cur == 0) return; 
        if(lvl == 0) cnt++;
        levels(cur -> left, lvl - 1); 
        levels(cur -> right, lvl - 1);
    }
public:
    BST(){
        root = 0;
    }
    void push(int x,int y,int z){
        push2(root,x,y,z);
    }
    void pushRoot(){
        root = new Node(1);
    }

    int levels(){
        int h = height(root);
        int mx = INT_MIN;
        int i = 0;
        while(h--){
            levels(root,i);
            if(cnt > mx) mx = cnt;
            cnt = 0;
            i++;
        }
        return mx;
    }
};
int main(){
    BST tree;
    int n; cin >> n;
    tree.pushRoot();
    int x, y, z;
    while(cin >> x >> y >> z){
        tree.push(x, y, z);
    }
    cout << tree.levels();
}
