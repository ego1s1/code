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

vector<vector<int>> preInPostTraversal(Node *node) {
    vi pre, in, post;
    stack<pair<Node *, int>> st;
    st.push({node, 1});
    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        if (it.se == 1) {
            pre.pb(it.fi->data);
            it.se++;
            st.push(it);
            if (it.fi->left != nullptr)
                st.push({it.fi->left, 1});
        } else if (it.se == 2) {
            in.pb(it.fi->data);
            it.se++;
            st.push(it);
            if (it.fi->right != nullptr)
                st.push({it.fi->right, 1});
        } else {
            post.pb(it.fi->data);
        }
    }
    vector<vi> ans;
    ans.pb(pre);
    ans.pb(in);
    ans.pb(post);
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
    vector<vi> ans = preInPostTraversal(root);
    for (auto it : ans) {
        for (int i : it) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
