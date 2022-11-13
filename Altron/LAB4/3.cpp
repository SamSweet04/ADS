#include <bits/stdc++.h>
using namespace std;
int mx = 0;
int mx_1 = 0;
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
        Node *root;
        Node *push(Node *cur,int val){
            if(cur == nullptr){
                return new Node(val);
            }
            if(val < cur->val) cur-> left = push(cur->left,val);
            if(val > cur->val) cur-> right = push(cur->right,val);
            return cur;
        }
        void inOrder(Node *cur){
            if(cur != nullptr){
                inOrder(cur->left);
                if(cur->val > mx){
                    mx_1 = mx;
                    mx = cur -> val;
                }
                if(cur-> val > mx_1 && cur-> val < mx){
                    mx_1 = cur-> val;
                }
                inOrder(cur->right);
            }
        }
    public:
        BST(){
            root = nullptr;
        }
        void push(int val){
            root = push(root,val);
        }
        void inOrder(){
            inOrder(root);
        }
};
    int main(){
        BST tree;
        int x;
        while(cin >> x && x != 0){
            tree.push(x);
        }
        tree.inOrder();
        cout << mx_1;
        return 0;
    }