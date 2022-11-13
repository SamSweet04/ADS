#include <bits/stdc++.h>
using namespace std;
int sum = 0;
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
    
    void inOrder(Node * cur){
    if (cur != nullptr){
        inOrder(cur -> left);
        cout << cur -> val << endl;
        inOrder(cur -> right);
    }
}
    void *greaterSum(Node *cur){
        if(cur != 0){
            greaterSum(cur->right);
            cur->val += sum;
            sum = cur->val;
            cout << cur->val << " ";
            greaterSum(cur->left);
        }
    }


public:
    BST(){
        root = nullptr;
    }

    void push(int val){
        root = push(root, val);
    }
    void inOrder()
{
        inOrder(root);
}    
void greaterSum(){
    greaterSum(root);
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
    tree.greaterSum();
    return 0;
} 