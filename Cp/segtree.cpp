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
// Any Associative operation following operator can be solved by segment tree &, |, ^
// Range minimum count
template <class T>
class SegmentTreeMinCount {
private:
    // Use a pair to store both the minimum value and the count of that value
    using Node = pair<T, int>;
    const Node DEFAULT = {std::numeric_limits<T>().max(), 0}; // for range min

    int len;
    vector<Node> segtree; // index 0 is the root

    // Combine function for range min and count
    Node combine(const Node &a, const Node &b) {
        if (a.first < b.first)
            return a; // a has min val
        if (b.first < a.first)
            return b; // b has min val
        return {a.first, a.second + b.second}; // If both have the same min, sum their counts
    }

    // Build the segment tree from the input array
    void build(const vector<T> &arr, int at, int at_left, int at_right) {
        if (at_left == at_right) {
            segtree[at] = {arr[at_left], 1}; // Each element appears once in the initial array
            return;
        }
        int mid = (at_left + at_right) / 2;
        build(arr, 2 * at + 1, at_left, mid);          // Build left child
        build(arr, 2 * at + 2, mid + 1, at_right);     // Build right child
        segtree[at] = combine(segtree[2 * at + 1], segtree[2 * at + 2]); // Combine the results
    }

    // Update the value at index `ind` to `val`
    void set(int ind, T val, int at, int at_left, int at_right) {
        if (at_left == at_right) {
            segtree[at] = {val, 1}; // Update the value and reset the count to 1
            return;
        }
        int mid = (at_left + at_right) / 2;
        if (ind <= mid) {
            set(ind, val, 2 * at + 1, at_left, mid);
        } else {
            set(ind, val, 2 * at + 2, mid + 1, at_right);
        }
        segtree[at] = combine(segtree[2 * at + 1], segtree[2 * at + 2]);
    }

    // Query the range [start, end] to get the min and its count
    Node range_query(int start, int end, int at, int at_left, int at_right) {
        if (at_right < start || end < at_left) {
            return DEFAULT; // Return default if out of range
        }
        if (start <= at_left && at_right <= end) {
            return segtree[at]; // Return the current node if it's fully within the range
        }
        int mid = (at_left + at_right) / 2;
        Node left_res = range_query(start, end, 2 * at + 1, at_left, mid);
        Node right_res = range_query(start, end, 2 * at + 2, mid + 1, at_right);
        return combine(left_res, right_res); // Combine the results from both sides
    }

public:
    SegmentTreeMinCount(int len) : len(len) { segtree = vector<Node>(len * 4, DEFAULT); }

    SegmentTreeMinCount(const vector<T> &arr) : len(arr.size()) {
        segtree = vector<Node>(len * 4, DEFAULT);
        build(arr, 0, 0, len - 1);
    }

    /** Sets the value at ind to val. */
    void set(int ind, T val) { set(ind, val, 0, 0, len - 1); }

    /** @return the minimum element and its count in the range [start, end] */
    pair<T, int> range_query(int start, int end) { return range_query(start, end, 0, 0, len - 1); }
};



// SegmentTree
template <class T>
class ClassicSegmentTree {
private:
    // const T DEFAULT = std::numeric_limits<T>().max(); // for range min
    // const T DEFAULT = std::numeric_limits<T>().min(); // for range max
    const T DEFAULT = 0; // for range sum

    int len;
    vector<T> segtree; // index 0 is the root

    // Combine function for range query (modify as needed for sum, min, or max)
    T combine(const T &a, const T &b) { return a + b; }

    // Build the segment tree from the input array
    void build(const vector<T> &arr, int at, int at_left, int at_right) {
        if (at_left == at_right) {
            segtree[at] = arr[at_left];
            return;
        }
        int mid = (at_left + at_right) / 2;
        build(arr, 2 * at + 1, at_left, mid);          // Build left child
        build(arr, 2 * at + 2, mid + 1, at_right);     // Build right child
        segtree[at] = combine(segtree[2 * at + 1], segtree[2 * at + 2]); // Combine the results
    }

    // Update the value at index `ind` to `val`
    void set(int ind, T val, int at, int at_left, int at_right) {
        if (at_left == at_right) {
            segtree[at] = val;
            return;
        }
        int mid = (at_left + at_right) / 2;
        if (ind <= mid) {
            set(ind, val, 2 * at + 1, at_left, mid);
        } else {
            set(ind, val, 2 * at + 2, mid + 1, at_right);
        }
        segtree[at] = combine(segtree[2 * at + 1], segtree[2 * at + 2]);
    }

    // Query range [start, end]
    T range_query(int start, int end, int at, int at_left, int at_right) {
        if (at_right < start || end < at_left) {
            return DEFAULT;
        }
        if (start <= at_left && at_right <= end) {
            return segtree[at];
        }
        int mid = (at_left + at_right) / 2;
        T left_res = range_query(start, end, 2 * at + 1, at_left, mid);
        T right_res = range_query(start, end, 2 * at + 2, mid + 1, at_right);
        return combine(left_res, right_res);
    }

    T find_leftmost(int val, int at, int l, int r) {
        if (segtree[at] < val) return -1; // no valid capacity here
        if (l == r) return l; // found exact index
        T m = (l + r) / 2;
        T left = find_leftmost(val, 2 * at + 1, l, m);
        if (left != -1) return left;
        return find_leftmost(val, 2 * at + 2, m + 1, r);
    }


public:
    ClassicSegmentTree(int len) : len(len) { segtree = vector<T>(len * 4, DEFAULT); }

    ClassicSegmentTree(const vector<T> &arr) : len(arr.size()) {
        segtree = vector<T>(len * 4, DEFAULT);
        build(arr, 0, 0, len - 1);
    }

    /** Sets the value at ind to val. */
    void set(int ind, T val) { set(ind, val, 0, 0, len - 1); }

    /** @return the range query result in the range [start, end] */
    T range_query(int start, int end) { return range_query(start, end, 0, 0, len - 1); }

    T find_leftmost_index(int val) { return find_leftmost(val, 0, 0, len - 1); }
};


//----------------------------------------------------------------------------------------------------------------------------------------------------------------
// for distinct count in a string, use bitmasking to store the distinct characters in a range
// 1 << (s[i] - 'a') will give the bitmask for the character s[i]
// for example, if s[i] = 'a', then 1 << (s[i] - 'a') = 1 << 0 = 1 (binary: 0001)
// if s[i] = 'b', then 1 << (s[i] - 'a') = 1 << 1 = 2 (binary: 0010)

template <class T = int>
class SegmentTreeBitmask {
private:
    int len;
    vector<T> segtree;

    // Combine function for bitmask
    T combine(const T &a, const T &b) { return a | b; }

    // Build the segment tree from the input string
    void build(const string &s, int at, int at_left, int at_right) {
        if (at_left == at_right) {
            segtree[at] = (1 << (s[at_left] - 'a'));
            return;
        }
        int mid = (at_left + at_right) / 2;
        build(s, 2 * at + 1, at_left, mid);
        build(s, 2 * at + 2, mid + 1, at_right);
        segtree[at] = combine(segtree[2 * at + 1], segtree[2 * at + 2]);
    }

    // Update the value at index `ind` to `val`
    void set(int ind, char val, int at, int at_left, int at_right) {
        if (at_left == at_right) {
            segtree[at] = (1 << (val - 'a')); // set the value 1 (mark it as present)
            return;
        }
        int mid = (at_left + at_right) / 2;
        if (ind <= mid) {
            set(ind, val, 2 * at + 1, at_left, mid);
        } else {
            set(ind, val, 2 * at + 2, mid + 1, at_right);
        }
        segtree[at] = combine(segtree[2 * at + 1], segtree[2 * at + 2]);
    }

    // Query range [start, end]
    T range_query(int start, int end, int at, int at_left, int at_right) {
        if (at_right < start || end < at_left) {
            return 0;
        }
        if (start <= at_left && at_right <= end) {
            return segtree[at];
        }
        int mid = (at_left + at_right) / 2;
        T left_res = range_query(start, end, 2 * at + 1, at_left, mid);
        T right_res = range_query(start, end, 2 * at + 2, mid + 1, at_right);
        return combine(left_res, right_res);
    }

public:
    SegmentTreeBitmask(const string &s) : len(s.size()) {
        segtree = vector<T>(len * 4, 0);
        build(s, 0, 0, len - 1);
    }

    void set(int ind, char val) { set(ind, val, 0, 0, len - 1); }

    /** @return the count of distinct characters in range [start, end] */
    int distinct_count(int start, int end) {
        return __builtin_popcount(range_query(start, end, 0, 0, len - 1));
    }
};

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//Segment tree subarray maximum
// SegmentTree<int> Sq(ar);
template<typename T>
struct SegmentTree {
    struct Node {
        T totsum;
        T mxPrefsum;
        T mxSuffsum;
        T mxSubarrsum;
    };
 
    int n;
    vector<Node> tree;
    T NEG_INF;
 
    SegmentTree(const vector<T>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        NEG_INF = numeric_limits<T>::lowest();
        build(arr, 0, 0, n - 1);
    }
 
    Node combine(const Node& left, const Node& right) {
        Node parent;
        parent.totsum = left.totsum + right.totsum;
        parent.mxPrefsum = max(left.mxPrefsum, left.totsum + right.mxPrefsum);
        parent.mxSuffsum = max(right.mxSuffsum, right.totsum + left.mxSuffsum);
        parent.mxSubarrsum = max({left.mxSubarrsum, right.mxSubarrsum, left.mxSuffsum + right.mxPrefsum});
        return parent;
    }
 
    void build(const vector<T>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            T val = arr[tl];
            tree[v] = {val, val, val, val};
        } else {
            int tm = (tl + tr) / 2;
            build(arr, v * 2 + 1, tl, tm);
            build(arr, v * 2 + 2, tm + 1, tr);
            tree[v] = combine(tree[v * 2 + 1], tree[v * 2 + 2]);
        }
    }
 
    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r) return {NEG_INF, NEG_INF, NEG_INF, NEG_INF};
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        Node left = query(v * 2 + 1, tl, tm, l, min(r, tm));
        Node right = query(v * 2 + 2, tm + 1, tr, max(l, tm + 1), r);
        if (left.totsum == NEG_INF) return right;
        if (right.totsum == NEG_INF) return left;
        return combine(left, right);
    }
 
    void update(int v, int tl, int tr, int pos, T new_val) {
        if (tl == tr) {
            tree[v] = {new_val, new_val, new_val, new_val};
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2 + 1, tl, tm, pos, new_val);
            else
                update(v * 2 + 2, tm + 1, tr, pos, new_val);
            tree[v] = combine(tree[v * 2 + 1], tree[v * 2 + 2]);
        }
    }
 
    T maxSubarray(int l, int r) {
        Node res = query(0, 0, n - 1, l, r);
        return res.mxSubarrsum;
    }
 
    void pointUpdate(int idx, T new_val) {
        update(0, 0, n - 1, idx, new_val);
    }
};

// For 0, 1 binary array count subarray
// SegtmentTree<int>Sg(ar);
template<typename T>
struct SegmentTree {
    struct Node {
        T len;       // segment length
        T max_len;   // max run of 1’s
        T prefix;    // prefix run of 1’s
        T suffix;    // suffix run of 1’s
    };

    int n;
    vector<Node> tree;

    SegmentTree(const vector<T>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
    }

    Node combine(const Node& left, const Node& right) {
        Node parent;
        parent.len = left.len + right.len;
        parent.prefix = (left.prefix == left.len) ? left.len + right.prefix : left.prefix;
        parent.suffix = (right.suffix == right.len) ? right.len + left.suffix : right.suffix;
        parent.max_len = max({left.max_len, right.max_len, left.suffix + right.prefix});
        return parent;
    }

    void build(const vector<T>& arr, int v, int tl, int tr) {
        if (tl == tr) {
            T val = arr[tl];
            tree[v] = {1, val, val, val};
        } else {
            int tm = (tl + tr) / 2;
            build(arr, v * 2, tl, tm);
            build(arr, v * 2 + 1, tm + 1, tr);
            tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    Node query(int v, int tl, int tr, int l, int r) {
        if (l > r) return {0, 0, 0, 0};
        if (l == tl && r == tr) return tree[v];
        int tm = (tl + tr) / 2;
        Node left = query(v * 2, tl, tm, l, min(r, tm));
        Node right = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(left, right);
    }

    void update(int v, int tl, int tr, int pos, T new_val) {
        if (tl == tr) {
            tree[v] = {1, new_val, new_val, new_val};
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    T maxRun(int l, int r) {
        return query(1, 0, n - 1, l, r).max_len;
    }

    void pointUpdate(int idx, T new_val) {
        update(1, 0, n - 1, idx, new_val);
    }
};

// most consecutively repeating character in segment
struct Node {
    char left_char, right_char;
    int left_count, right_count, max_count;
    int len;

    Node(char c = 0) : left_char(c), right_char(c),
        left_count(1), right_count(1), max_count(1) {}

    static Node merge(const Node& a, const Node& b) {
        Node res;
        res.left_char = a.left_char;
        res.right_char = b.right_char;

        res.left_count = a.left_count;
        if (a.left_count == a.len && a.left_char == b.left_char)
            res.left_count = a.left_count + b.left_count;

        res.right_count = b.right_count;
        if (b.right_char == a.right_char && b.right_count == b.len)
            res.right_count = a.right_count + b.right_count;

        res.max_count = max(a.max_count, b.max_count);
        if (a.right_char == b.left_char)
            res.max_count = max(res.max_count, a.right_count + b.left_count);
        res.len = a.len + b.len;
        return res;
    }
};

class SegmentTree2 {
    vector<Node> tree;
    int n;

public:
    SegmentTree2(const string& s) {
        n = s.size();
        tree.resize(4 * n);
        build(s, 1, 0, n - 1);
    }

    void build(const string& s, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = Node(s[tl]);
        } else {
            int tm = (tl + tr) / 2;
            build(s, v * 2, tl, tm);
            build(s, v * 2 + 1, tm + 1, tr);
            tree[v] = Node::merge(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    void update(int pos, char c, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = Node(c);
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(pos, c, v * 2, tl, tm);
            else
                update(pos, c, v * 2 + 1, tm + 1, tr);
            tree[v] = Node::merge(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    void update(int pos, char c) {
        update(pos, c, 1, 0, n - 1);
    }

    Node query(int l, int r, int v, int tl, int tr) {
        if (l > r) return Node();
        if (l == tl && r == tr) return tree[v];

        int tm = (tl + tr) / 2;
        return Node::merge(
            query(l, min(r, tm), v * 2, tl, tm),
            query(max(l, tm + 1), r, v * 2 + 1, tm + 1, tr)
        );
    }

    int query(int l, int r) {
        return query(l, r, 1, 0, n - 1).max_count;
    }
};


// Lazy propagation: Range update, range query
template <class T> class LazySegmentTree {
private:
    int n;
    vector<T> tree, lazyAdd, lazySet;
    vector<bool> hasLazySet; // marks if a node has a pending set

    T combine(T a, T b) { return a + b; } // range sum

    void applyAdd(int node, int l, int r, T val) {
        if (hasLazySet[node]) {
            lazySet[node] += val; // adjust the set value
        } else {
            lazyAdd[node] += val;
        }
        tree[node] += val * (r - l + 1);
    }

    void applySet(int node, int l, int r, T val) {
        tree[node] = val * (r - l + 1);
        lazySet[node] = val;
        hasLazySet[node] = true;
        lazyAdd[node] = 0;
    }

    void push(int node, int l, int r) {
        if (l == r)
            return;
        int mid = (l + r) / 2;
        if (hasLazySet[node]) {
            applySet(node * 2 + 1, l, mid, lazySet[node]);
            applySet(node * 2 + 2, mid + 1, r, lazySet[node]);
            hasLazySet[node] = false;
        }
        if (lazyAdd[node] != 0) {
            applyAdd(node * 2 + 1, l, mid, lazyAdd[node]);
            applyAdd(node * 2 + 2, mid + 1, r, lazyAdd[node]);
            lazyAdd[node] = 0;
        }
    }

    void updateAdd(int ql, int qr, T val, int node, int l, int r) {
        if (qr < l || r < ql)
            return;
        if (ql <= l && r <= qr) {
            applyAdd(node, l, r, val);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        updateAdd(ql, qr, val, node * 2 + 1, l, mid);
        updateAdd(ql, qr, val, node * 2 + 2, mid + 1, r);
        tree[node] = combine(tree[node * 2 + 1], tree[node * 2 + 2]);
    }

    void updateSet(int ql, int qr, T val, int node, int l, int r) {
        if (qr < l || r < ql)
            return;
        if (ql <= l && r <= qr) {
            applySet(node, l, r, val);
            return;
        }
        push(node, l, r);
        int mid = (l + r) / 2;
        updateSet(ql, qr, val, node * 2 + 1, l, mid);
        updateSet(ql, qr, val, node * 2 + 2, mid + 1, r);
        tree[node] = combine(tree[node * 2 + 1], tree[node * 2 + 2]);
    }

    T query(int ql, int qr, int node, int l, int r) {
        if (qr < l || r < ql)
            return 0;
        if (ql <= l && r <= qr)
            return tree[node];
        push(node, l, r);
        int mid = (l + r) / 2;
        return combine(query(ql, qr, node * 2 + 1, l, mid),
                        query(ql, qr, node * 2 + 2, mid + 1, r));
    }

public:
    LazySegmentTree(int n) : n(n) {
        tree.assign(4 * n, 0);
        lazyAdd.assign(4 * n, 0);
        lazySet.assign(4 * n, 0);
        hasLazySet.assign(4 * n, false);
    }

    void build(const vector<T>& arr, int node, int l, int r) {
        if (l == r) {
            tree[node] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, node * 2 + 1, l, mid);
        build(arr, node * 2 + 2, mid + 1, r);
        tree[node] = combine(tree[node * 2 + 1], tree[node * 2 + 2]);
    }

    void build(const vector<T>& arr) { build(arr, 0, 0, n - 1); }

    // Public API
    void rangeAdd(int l, int r, T val) {
        updateAdd(l, r, val, 0, 0, n - 1);
    }
    void rangeSet(int l, int r, T val) {
        updateSet(l, r, val, 0, 0, n - 1);
    }
    T rangeQuery(int l, int r) { return query(l, r, 0, 0, n - 1); }
};
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// 28-01-2025
// Binary Indexed Tree (or) Fenwick Tree: 
// Used for Range dynamic queries
// Static queries we can do: N <= 1e7, take upto k=25
// Sum: O(n) Prefix sum
//      for each query in O(1), preprocessing takes O(n) ;
// Min or Max: O(nlogn) Using sparse table dp[n][1<<n];
//             for each query can do in logn tc, Preprocessing takes O(nlogn);
// Xor : same as Sum

// SPARSE TABLE METHOD
// Use Zero indexing structure
#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 1, mod = (int)(1e9 + 7);
#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define forl(i, a, b, k) for (ll i = a; i < b; i += k)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define pb push_back

template<class T> 
class SparseTable {
private:
    int MAXN, k;
    vector<vector<T>> st;
    vector<T> lg, arr;

public:
    SparseTable(int size) : MAXN(size), k((int)log2(size)), lg(size + 1), arr(size), st(size, vector<T>(k + 1, -1)) {}

    void set(int idx, T val) {
        arr[idx] = val;
    }

    void init() {
        lg[0] = 0;
        lg[1] = 0;
        for (int i = 2; i <= MAXN; ++i) {
            lg[i] = lg[i/2] + 1;
        }
        for (int i = 0; i < MAXN; ++i) {
            st[i][0] = arr[i];
        }
        for (int p = 1; p <= k; ++p) {
            for (int i = 0; i + (1 << p) <= MAXN; ++i) {
                st[i][p] = __gcd(st[i][p - 1], st[i + (1 << (p - 1))][p - 1]);
            }
        }
    }

    T get_query(int l, int r) {
        int len = r - l + 1;
        int p = lg[len];
        return __gcd(st[l][p], st[r - (1 << p) + 1][p]);
    }
};


void batman()
{
	int n;
	cin >> n;
	SparseTable<long long> st(n);
	for (int i = 0; i < n;i++){
		int val;
		cin >> val;
		st.set(i, val);
	}
	st.init();
	int q;
    cin >> q;
    for (int i = 0; i < q;i++){
        int l,r;
        cin >> l >> r;
		cout << st.get_query(l, r) << endl;
	}
}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        batman();
    }
}



// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define pb push_back

// template<typename T>
// struct SegmentTree {
//     struct Node {
//         T tot;
//         T pref;
//         T suff;
//         T ans;
//     };

//     int n;
//     vector<Node> tree;
//     T NEG_INF;

//     SegmentTree(int sz) {
//         n = sz;
//         tree.resize(4 * n);
//         NEG_INF = numeric_limits<T>::min() / 4; // avoid overflow
//         // initialize leaves/inner nodes to sentinel
//         for (int i = 0; i < 4 * n; ++i) tree[i] = {NEG_INF, NEG_INF, NEG_INF, NEG_INF};
//     }

//     Node combine(const Node& l, const Node& r) {
//         Node par;
//         par.tot = l.tot + r.tot;
//         par.pref = max(l.pref, l.tot + r.pref);
//         par.suff = max(r.suff, r.tot + l.suff);
//         par.ans = max({l.ans, r.ans, l.suff + r.pref});
//         return par;
//     }

//     Node query(int v, int tl, int tr, int l, int r) {
//         if (l > r) {
//           return {NEG_INF, NEG_INF, NEG_INF, NEG_INF};
//         }
//         if (l == tl && r == tr) {
//           return tree[v];
//         }
//         int tm = (tl + tr) / 2;
//         Node left = query(v * 2 + 1, tl, tm, l, min(r, tm));
//         Node right = query(v * 2 + 2, tm + 1, tr, max(l, tm + 1), r);
//         if (left.tot == NEG_INF) return right;
//         if (right.tot == NEG_INF) return left;
//         return combine(left, right);
//     }

//     void update(int v, int tl, int tr, int pos, T new_val) {
//         if (tl == tr) {
//             tree[v] = {new_val, new_val, new_val, new_val};
//         } else {
//             int tm = (tl + tr) / 2;
//             if (pos <= tm)
//                 update(v * 2 + 1, tl, tm, pos, new_val);
//             else
//                 update(v * 2 + 2, tm + 1, tr, pos, new_val);
//             Node L = tree[v * 2 + 1], R = tree[v * 2 + 2];
//             if (L.tot == NEG_INF) tree[v] = R;
//             else if (R.tot == NEG_INF) tree[v] = L;
//             else tree[v] = combine(L, R);
//         }
//     }

//     T maxSubarray(int l, int r) {
//         Node res = query(0, 0, n - 1, l, r);
//         return res.ans;
//     }

//     void pointUpdate(int idx, T new_val) {
//         update(0, 0, n - 1, idx, new_val);
//     }
// };

// inline void solve() {
//   int n, q;
//   cin >> n >> q;
//   vector<int> val(n + 1);
//   for (int i = 1; i <= n; i++) cin >> val[i];

//   vector<vector<int>> g(n + 1);
//   for (int i = 0; i < n - 1; i++) {
//     int a, b;
//     cin >> a >> b;
//     g[a].pb(b), g[b].pb(a);
//   }

// //   SegmentTree<int> st(n);

//   vector<int> lvl(n + 1), subs(n + 1), par(n + 1);
//   vector<int> tp(n + 1), id(n + 1);

//   function<void(int,int)> dfs1 = [&](int u, int p) {
//     subs[u] = 1;
//     par[u] = p;
//     for (auto ch : g[u]) {
//       if (ch == p) continue;
//       lvl[ch] = lvl[u] + 1;
//       dfs1(ch, u);
//       subs[u] += subs[ch];
//     }
//   };

//   int timer = 0;
//   function<void(int,int,int)> hld = [&](int u, int p, int top) {
//     id[u] = timer++;
//     tp[u] = top;
//     st.pointUpdate(id[u], val[u]);
//     int h_ch = -1, h_sz = -1;
//     for (auto ch : g[u]) {
//       if (ch == p) continue;
//       if (subs[ch] > h_sz) {
//         h_sz = subs[ch];
//         h_ch = ch;
//       }
//     }
//     if (h_ch != -1) hld(h_ch, u, top);
//     for (auto ch : g[u]) {
//       if (ch == p || ch == h_ch) continue;
//       hld(ch, u, ch);
//     }
//   };

//   function<int(int,int)> path = [&](int x, int y) {
//     int ret = numeric_limits<int>::min();
//     while (tp[x] != tp[y]) {
//       if (lvl[tp[x]] < lvl[tp[y]])  {
//         swap(x, y);
//       }
//       int l = id[tp[x]], r = id[x];
//       if (l > r) {
//         swap(l, r);
//       }
//       ret = max(ret, st.maxSubarray(l, r));
//       x = par[tp[x]];
//     }
//     if (lvl[x] > lvl[y]) {
//       swap(x, y);
//     }
//     int l = id[x], r = id[y];
//     if (l > r) {
//       swap(l, r);
//     }
//     ret = max(ret, st.maxSubarray(l, r));
//     return ret;
//   };

//   lvl[1] = 0;
//   dfs1(1, 0);
//   timer = 0;
//   hld(1, 0, 1);

//   while (q--) {
//     int u, v;
//     cin >> u >> v;
//     cout << path(u, v) << endl;
//   }
// }

// signed main() {
//   ios::sync_with_stdio(false);
//   cin.tie(nullptr);
//   int tc = 1;
//   while (tc--) solve();
//   return 0;
// }
