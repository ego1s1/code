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

void iter_preorder(Node *node) {
    stack<Node *> st;
    int size;
    st.push(node);
    while (!st.empty()) {
        Node *top = st.top();
        st.pop();
        cout << top->data << " ";
        if (top->right != nullptr)
            st.push(top->right);
        if (top->left != nullptr)
            st.push(top->left);
    }
}

int main() {
    int n;
    cin >> n;
    struct Node *root = new Node(n);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    iter_preorder(root);
    return 0;
}
