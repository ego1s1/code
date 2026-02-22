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

stack<int> iter_postorder(Node *node) {
    stack<Node *> st;
    stack<int> ans;
    st.push(node);
    while (!st.empty()) {
        if (node->left != nullptr)
            st.push(node);
        if (node->right != nullptr)
            st.push(node);
        ans.push(node->data);
        node = st.top();
        st.pop();
    }
    return ans;
}
stack<int> iter_post_single_stack(Node *node) {
    stack<Node *> st;
    stack<int> post;
    Node *curr = node;
    while (curr != nullptr || !st.empty()) {
        if (curr != nullptr) {
            st.push(curr);
            curr = curr->left;
        } else {
            Node *temp = st.top()->right;
            if (temp == nullptr) {
                temp = st.top();
                st.pop();
                post.push(temp->data);
                while (!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    post.push(temp->data);
                }
            } else
                curr = temp;
        }
    }
    return post;
}
int main() {
    int n;
    cin >> n;
    struct Node *root = new Node(n);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    stack<int> postorder = iter_post_single_stack(root);
    while (!postorder.empty()) {
        cout << postorder.top() << " ";
        postorder.pop();
    }
    return 0;
}
