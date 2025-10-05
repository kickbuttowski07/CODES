#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1, MOD = (int)(1e9 + 7);
#define int long long
#define ll long long
#define forl(i, a, b, k) for (ll i = a; i < b; i += k)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define pb push_back
#define F first
#define S second

// Main Link
// https://www.geeksforgeeks.org/dsa/binary-tree-data-structure/

class Node {
public:
    int data;
    Node *left, *right;
    int subtree;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
        subtree = 1;
    }
};

inline void solve() {
    Node *root = new Node(5);
    root->left = new Node(7);
    root->right = new Node(8);
    root->left->left = new Node(10);
    root->left->right = new Node(11);
    root->right->left = new Node(4);
    root->right->right = new Node(12);
    root->right->right->left = new Node(13);

    function<void(Node *)> inorder = [&](Node *root) -> void {
        if(root->left == nullptr && root->right == nullptr){
            cout << root->data << " ";
            return;
        }
        // rearrange according to inorder(L, Root, R), preorder(Root, L, R), postorder(L, R, Root)
        if(root->left != nullptr) {
            inorder(root->left);
        }
        cout << root->data << " ";
        if(root->right!=nullptr) {
            inorder(root->right);
        }
    };
    inorder(root);
    cout << endl;
    function<int(Node *)> height = [&](Node *root) -> int {
        if(root->left == nullptr && root->right == nullptr){
            return 1;
        }

        int mx = 1;
        if(root->left != nullptr) {
            mx = max(mx, 1 + height(root->left));
        }
        if(root->right != nullptr) {
            mx = max(mx, 1 + height(root->right));
        }
        return mx;
    };
    cout << height(root) << endl;

    function<void(Node *)> subsize = [&](Node *root) -> void {
        if(root->left == nullptr && root->right == nullptr){
            return;
        }
        if(root->left != nullptr) {
            subsize(root->left);
            root->subtree += root->left->subtree;
        }
        if(root->right!=nullptr) {
            subsize(root->right);
            root->subtree += root->right->subtree;
        }
    };
    subsize(root);

    function<void(Node *)> dfs = [&](Node *root) -> void {
        if(root->left == nullptr && root->right == nullptr){
            cout << root->data << " " << "size =" << root->subtree << endl;
            return;
        }
        if(root->left != nullptr) {
            dfs(root->left);
        }
        cout << root->data << " " << "size =" << root->subtree << endl;
        if(root->right!=nullptr) {
            dfs(root->right);
        }
    };
    dfs(root);

    int mx = 0, mi = INT_MAX;
    function<void(Node *)> mxmi = [&](Node *root) -> void {
        if(root == nullptr) {
            return;
        }
        mx = max(mx, root->data);
        mi = min(mi, root->data);
        mxmi(root->left);
        mxmi(root->right);
    };
    mxmi(root);
    cout << "mx = " << mx << " " << "mi = " << mi << endl;

    // sum tree = node value is subtree sum - its value
    function<bool(Node *)> fun1 = [&](Node *root) -> bool {
        if(root == nullptr) {
            return true;
        }
        int sum = 0;
        bool chk = true;
        if(root->left != nullptr) {
            sum += root->left->subtree;
            chk &= fun1(root->left);
        }
        if(root->right!=nullptr) {
            sum += root->right->subtree;
            chk &= fun1(root->right);
        }
        return (sum == root->data) && chk;
    };
    cout << fun1(root) << endl;

    // Node* root1 = new Node(1);
    // root1->left = new Node(3);
    // root1->right = new Node(2);
    // root1->right->left = new Node(5);
    // root1->right->right = new Node(4);

    // Node* root2 = new Node(1);
    // root2->left = new Node(2);
    // root2->right = new Node(3);
    // root2->left->left = new Node(4);
    // root2->left->right = new Node(5);
    // Sample input 

    function<bool(Node*, Node*)> Identical = [&](Node* r1, Node* r2) -> bool {
        bool v1 = r1 == nullptr, v2 = r2 == nullptr;
        if (v1 ^ v2) return false;        // One null, one not
        if (v1 && v2) return true;        // Both null
        if (r1->data != r2->data) return false;
        return Identical(r1->left, r2->left) && Identical(r1->right, r2->right);
    };

    function<bool(Node*, Node*)> ismirror = [&](Node* r1, Node* r2) -> bool {
        bool v1 = r1 == nullptr, v2 = r2 == nullptr;
        if (v1 ^ v2) return false;        // One null, one not
        if (v1 && v2) return true;        // Both null
        if (r1->data != r2->data) return false;
        return ismirror(r1->left, r2->right) && ismirror(r1->right, r2->left);
    };
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t = 1;
    cin >> t;
    for (int _ = 1; _ <= t; _++) {
        solve();
    }

    return 0;
}

// JAI SHREE RAM