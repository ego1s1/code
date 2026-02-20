#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rep(i, a, b) for (int i = a; i < b; i++)

struct Node {
  int data;
  Node *left;
  Node *right;

  Node(int val) {
    data = val;
    left = right = nullptr;
  }
};

vector<vector<int>> levelorder(Node* root) {
  vector<vector<int>> ans;
  if(root == nullptr) return ans;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
    int size = q.size();
    vector<int> level;
    for(int i = 0;i<size;i++){
        Node* node = q.front();
        q.pop();
        if(node->left != nullptr) q.push(node->left);
        if(node->right != nullptr) q.push(node->right);
        level.push_back(node->data);
    }
    ans.push_back(level);
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  struct Node *root = new Node(n);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);   
  root->left->right = new Node(5);
  root->right->left = new Node(6);   
  root->right->right = new Node(7);
  vector<vector<int>> ans = levelorder(root);
  for(int i = 0; i<ans.size();i++){
    for(int j = 0;j<ans[i].size();j++){
        cout << ans[i][j] << ' ';
    }
    cout << endl;
  }
  return 0;
}