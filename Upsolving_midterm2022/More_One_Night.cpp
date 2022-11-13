#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int val){
        this->val = val;
        right = left = nullptr;
    }
};

class bst{
  node* root;
  node* add(node* cur, int val){
      if(!cur) return new node(val);
      if(val > cur->val) cur->right = add(cur->right, val);
      else cur->left = add(cur->left, val);
      return cur;
  }
  int cnt = 0;
  void count(node* cur){
      if(!cur) return;
      if(!cur->left && !cur->right) cnt++;
      count(cur->left);
      count(cur->right);
  }
  public:
  bst(){
      root = nullptr;
  }
  void add(int val){
      root = add(root, val);
  }
  void print(){
      count(root);
      cout << cnt;
  }
};

int main(){
    bst *b = new bst();
    int n; cin >> n;
    while(n--){
        int val; cin >> val;
        b->add(val);
    }
    b->print();
    
    return 0;
}