#include <bits/stdc++.h>
using namespace std;
struct Node {
	Node *right;
	Node *left;
	int val;
	int cnt;
	Node(int val){
		this->val = val;
		this->cnt = 1;
		right = left = 0;
	}
};
struct BST{
private:
	Node *root;
	Node *push(Node *cur,int val){
		if(cur == 0) return new Node(val);
		if(cur -> val == val) cur->cnt++;
		if(val < cur->val) cur->left = push(cur->left,val);
		if(val > cur-> val) cur->right = push(cur->right,val);
		return cur;
	}

	void show(Node *cur,int val){
		if(cur == 0) return;
		if(cur->val == val){ 
		cout << cur->cnt << endl;
		return;
	}
		if(cur->val > val) {
			show(cur->left,val);
		}
		if(cur->val < val){
			show(cur->right,val);
		}
	}
	void del(Node *cur,int val){
		if(cur == 0) return;
		if(cur->val == val){
			if(cur->cnt > 0){ 
				cur->cnt --;
			}
			return;
		}
		if(cur->val > val) del(cur->left,val);
		if(cur->val < val) del(cur->right,val);
	}
public:
	BST(){
		root = 0;
	}
	void push(int val){
		root = push(root, val);
	}
	void show(int val){
		show(root,val);
	}
	void del(int val){
		del(root,val);
	}
};
int main(){
	BST bst;
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		if(s == "insert"){
			int x;
			cin >> x;
			bst.push(x);
		}
		if(s == "cnt"){
			int x;
			cin >> x;
			bst.show(x);
		}
		if(s == "delete"){
			int x;
			cin >> x;
			bst.del(x);
		}
	}
}