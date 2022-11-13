#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node *left;
    Node *right;
    int val;
    Node(int _val){
        val = _val;
        left = right = 0;
    }
};
class BST{
private:
    Node *root;
    Node *push(Node *cur,int val){
        if(cur == 0) return new Node(val);
        if(val < cur->val) {
            cur->left = push(cur->left,val);
        }
        if(val > cur->val) {
            cur->right = push(cur->right,val);
        }
        return cur;    
    }
    void print(Node *cur){
        if(cur != 0 ){
            print(cur->left);
            cout << cur->val << endl;
            print(cur->right); 
        }
    }
    void dfs(Node *cur, vector <int> &ans){
        if(!cur) return;
        int i = 0;
        Node *left = cur->left;
        Node *right = cur->right;
        while(left != 0  && right != 0){
            ans[i]+=1;
            left = left->left;
            right = right->right;
            i++;
        }
        dfs(cur->left,ans);
        dfs(cur->right,ans);

    }
public:
    BST(){
        root = 0;
    }
    void push(int val){
        root = push(root,val);
    }
    void print(){
        print(root);
    }
    int dfs(vector<int> &ans){
        dfs(root,ans);
    }
};
int main(){
    BST bst;
    int n,k;
    cin >> n;
    vector<int> ans(n-1);
    while(n--){
        cin >> k;
        bst.push(k);
    }
    bst.dfs(ans);
    for (auto i : ans) {
		cout << i << " ";
	}

	return 0;
}