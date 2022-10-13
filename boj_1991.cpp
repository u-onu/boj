#include <bits/stdc++.h>
using namespace std;

struct node{
  char name;
  int left, right;

  void set_node(char name, char left_name, char right_name){
    this->name = name;
    if(left_name == '.') this->left = -1;
    else this->left = left_name - 'A';
    if(right_name == '.') this->right = -1;
    else this->right = right_name - 'A';
  }
};

vector<struct node> tree;

void pre_order(int root){
  if(root == -1) return;
  cout << tree[root].name;
  pre_order(tree[root].left);
  pre_order(tree[root].right);
}

void in_order(int root){
  if(root == -1) return;
  in_order(tree[root].left);
  cout << tree[root].name;
  in_order(tree[root].right);
}

void post_order(int root){
  if(root == -1) return;
  post_order(tree[root].left);
  post_order(tree[root].right);
  cout << tree[root].name;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  // freopen("input.txt", "r", stdin);

  int n;
  cin >> n;
  tree.resize(n);

  char p, l, r;
  for(int i = 0; i < n; i++){
    cin >> p >> l >> r;
    tree[p - 'A'].set_node(p, l, r);
  }

  pre_order(0);
  cout << '\n';
  in_order(0);
  cout << '\n';
  post_order(0);
  cout << '\n';  
}