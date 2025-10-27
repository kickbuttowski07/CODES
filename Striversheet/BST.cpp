#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1, MOD = (int)(1e9 + 7);
#define int long long
#define ll long long
#define forl(i, a, b, k) for (ll i = a; i < b; i += k)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define pb push_back
                                    
                                    
#define F first
#define S second

// insertion main conditions
// if(curr->data < key && curr->right) {
//     curr=curr->right;
// }
// else if(curr->data > key && curr->left){
//     curr=curr->left;
// }
// else{
//     break;
// }

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int data) {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

bool isBST(Node* root, int mi, int mx) {
    if(root == nullptr) {
        return true;
    }
    if(mi >= root->data || mx <= root->data) {
        return false;
    }
    return isBST(root->left, mi, root->data) && isBST(root->right, root->data, mx);
}

Node* LCA(Node* root, Node* left, Node* right) {
    int lval = left->data, rval = right->data;
    while(root != nullptr) {
        if(root->data > lval && root->data > rval) {
            root = root->left;
        }
        else if(root->data < lval && root->data < rval) {
            root = root->right;
        }
        else{
            break;
        }
    }
    return root;
}

void sorting(Node* root, Node*& first, Node*& mid, Node*& last, Node*& prev) {
    if (root == nullptr) {
        return;
    }
    sorting(root->left, first, mid, last, prev);
    if (prev && root->data < prev->data) {
        if (!first) {
            first = prev;
            mid = root; // 1 violation
        } else {
            last = root; // 2 violations
        }
    }
    prev = root;
    sorting(root->right, first, mid, last, prev);
}
Node* built(int left, int right, vector<int>&arr) {
    if(right < left) {
        return nullptr;
    }
    int mid = (left + right) / 2;
    Node *curr = new Node(arr[mid]);
    curr->left = built(left, mid - 1, arr);
    curr->right = built(mid + 1, right, arr);
    return curr;
}

// check leaves too, k-smallest, (k-largest (use reverse Morris));
vector<int> MorrisInorder(Node* root) {
    vector<int> ans;
    Node *curr = root;
    while(curr != nullptr) {
        if(curr->left == nullptr) {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node *prev = curr->left;
            while(prev->right && prev->right != curr) {
                prev = prev->right;
            }
            if(prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
                // ans.push_back(curr->data) for preorder;
                // for postorder do reverse.
                // in both remove ans.push_back(curr->data) from else condition
            }
            else{
                prev->right = nullptr;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}




vector<int> LargestBST(Node* root) {
    if(root == nullptr) {
        return {INT_MAX, INT_MIN, 0};
    }
    if(!root->left && !root->right) {
        return {root->data, root->data, 1};
    }

    vector<int> left = LargestBST(root->left);
    vector<int> right = LargestBST(root->right);
    vector<int> ans(3);
    if(root->data < right[0] && root->data > left[1]) {
        ans = {min(left[0], root->data), max(root->data, right[1]), left[2] + right[2] + 1};
    }
    else{
        ans[0] = INT_MIN;
        ans[1] = INT_MAX;
        ans[2] = -1;
    }
    return ans;
}



inline void solve() {
    
}
                        
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
             
    int t = 1;
    cin >> t;
    for(int _ = 1; _ <= t; _++) {
        // cout << "Caso #" << _ << endl;
        solve();
    }
                
    return 0;
}
// JAI SHREE RAM