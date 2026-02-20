#include <bits/stdc++.h>
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

void preorder(Node* node) {
  if (node == nullptr) {
    return;
  }
  cout << node->data << endl;
  preorder(node->left);
  preorder(node->right);
}

int main() {
  int n;
  cin >> n;
  struct Node *root = new Node(n);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);   
  root->left->right = new Node(5);
  preorder(root);
  return 0;
}