#include <bits/stdc++.h>
using namespace std;

const int N = 1e4, MOD = (int)(1e9 + 7);
#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define forl(i, a, b, k) for (ll i = a; i < b; i += k)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define pb push_back

inline void solve()
{
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}



// https://leetcode.com/problems/rank-transform-of-a-matrix/description/
template <class T = int> class DSUg {
private:
    int size;
    vector<T> par;
    vector<T> sizes;

public:
    DSUg(int size) : size(size), par(size), sizes(size, 1) {
        for (int i = 0; i < size; i++) {
            par[i] = i;
        }
    }
    int find(int x) { // O(logn)
        return par[x] == x ? x : (par[x] = find(par[x]));
    }
    bool unite(int x, int y) { // O(logn)
        if (connected(x, y)) {
            return false; // Cycle detected
        }
        int x_root = find(x);
        int y_root = find(y);

        if (sizes[x_root] < sizes[y_root]) {
            swap(x_root, y_root);
        }
        sizes[x_root] += sizes[y_root];
        par[y_root] = x_root;
        return true; // No cycle
    }

    bool connected(int x, int y) { return find(x) == find(y); } // O(logn)
};

template <class T = int>
class DSU2D {
private:
    int rows, cols;
    vector<T> par;
    vector<T> sizes;

    int index(int i, int j) const {
        return i * cols + j;
    }

public:
    DSU2D(int r, int c) : rows(r), cols(c), par(r * c), sizes(r * c, 1) {
        for (int i = 0; i < r * c; ++i) {
            par[i] = i;
        }
    }

    int find(int i, int j) {
        int idx = index(i, j);
        if (par[idx] != idx)
            par[idx] = find(par[idx] / cols, par[idx] % cols);
        return par[idx];
    }

    bool connected(int i1, int j1, int i2, int j2) {
        return find(i1, j1) == find(i2, j2);
    }

    bool unite(int i1, int j1, int i2, int j2) {
        int root1 = find(i1, j1);
        int root2 = find(i2, j2);
        if (root1 == root2) return false; // Already connected

        if (sizes[root1] < sizes[root2])
            swap(root1, root2);

        sizes[root1] += sizes[root2];
        par[root2] = root1;
        return true;
    }

    int size(int i, int j) {
        return sizes[find(i, j)];
    }
};
// size and Rank
template <class T = int> class DSU {
private:
    int size;
    vector<T> par;
    vector<T> sizes;
    vector<T> rank;

public:
    DSU(int size) : size(size), par(size), sizes(size, 1), rank(size, 0) {
        for (int i = 0; i < size; i++) {
            par[i] = i;
        }
    }

    /** @return the "representative" node in x's component */
    int find(int x) {
        // O(logn)
        return par[x] == x ? x : (par[x] = find(par[x]));
    }

    /** @return whether the merge changed connectivity */
    bool unite_by_sizes(int x, int y) {
        // O(logn) 
        if(connected(x, y)) {
            return false; // Cycle detected
        }
        int x_root = find(x);
        int y_root = find(y);

        if (sizes[x_root] < sizes[y_root]) {
            swap(x_root, y_root);
        }
        sizes[x_root] += sizes[y_root];
        par[y_root] = x_root;
        return true;// No cycle
    }

    bool unite_by_rank(int x, int y) {
        if(connected(x, y)) {
            return false; // Cycle detected
        }
        int x_root = find(x);
        int y_root = find(y);
        
        if (rank[x_root] < rank[y_root]) {
            swap(x_root, y_root);
        }
        par[y_root] = x_root;
        if (rank[x_root] == rank[y_root]) {
            rank[x_root]++;
        }

        return true;// No cycle
    }

    /** @return whether x and y are in the same connected component */
    bool connected(int x, int y) { return find(x) == find(y); } // O(logn)
};