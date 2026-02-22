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

vector<int> iter_inorder(Node *node) {
    stack<Node *> st;
    vi inorder;
    while (true) {
        if (node != nullptr) {
            st.push(node);
            node = node->left;
        } else {
            if (st.empty())
                break;
            node = st.top();
            st.pop();
            inorder.pb(node->data);
            node = node->right;
        }
    }
    return inorder;
}

int main() {
    int n;
    cin >> n;
    struct Node *root = new Node(n);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    vector<int> inorder = iter_inorder(root);
    for (int i : inorder)
        cout << i << " ";
    return 0;
}
