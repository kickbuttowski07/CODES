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

// notes:
// If the graph was originally not connected, then there doesn't exist a spanning tree,
// so the number of selected edges will be less than n - 1
// Prims :
// Dense O(n^ 2)(more no of edges relative to vertices), Sparse(m log n)(small no of edges relative to vertices)
// Mininum Spanning Trees by kruskal algorithm
int spanningTree(int V, vector<vector<int>> adj[]) {
    // code here
    vector<vector<int>> edges;
    for (int u = 0; u < V; ++u) {
        for (auto it : adj[u]) {
            int v = it[0];
            int weight = it[1];
            if (u < v) {
                edges.push_back({weight, u, v});
            }
        }
    }
    sort(edges.begin(), edges.end());
    vector<int> parent(V, -1), rank(V, 1);
    // use DSU instead;
    auto find = [&](int i, auto &&ref) -> int {
        if (parent[i] == -1) {
            return i;
        }
        return parent[i] = ref(parent[i], ref);
    };
    auto unite = [&](int x, int y) -> void {
        int s1 = find(x, find);
        int s2 = find(y, find);

        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            }
            else {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    };
    int sum = 0;
    for (auto i : edges) {
        int x = i[0], y = i[1], z = i[2];
        if (find(y, find) != find(z, find)) {
            unite(y, z);
            sum += x;
        }
    }
    return sum;
}

// TOPO SORT
// Only exists in DAG 
// If the nodes of a graph are connected through directed edges and 
// the graph does not contain a cycle, it is called a directed acyclic graph(DAG). 
// Defination: The topological sorting of a directed acyclic graph is nothing but the linear ordering of vertices such that,
// if there is an edge between node u and v(u -> v), node u appears before v in that ordering.
// O(V + E) + O(V), O(2N)
vector<vector<int>> g;
stack<int> st; 
function<void(int)> topo_sort = [&](int src) ->void {
    vis[src] = true;
    for (auto child : g[src]) {
        if (!vis[child]) {
            topo_sort(child);
        }
    }
    // DAG only
    st.push(src);
};
// vector<int> ans;
// while (!st.empty()) {
//     ans.push_back(st.top());
//     st.pop();
// }
// return ans;


// Kahn's Algorithm 
// It depends upon indegree of the nodes
vector<bool> vis(N, false);
vector<int> ind(N, 0);
queue<int> q;
vector<int> adj[N];
auto kahn_alg = [&]() -> vector<int> {
    for (int u = 0; u < N; u++) {
        for (auto v : adj[u]) {
            g[u].push_back(v);
            ind[v]++;
        }
    }
    for (int i = 0; i < N; i++) {
        if (ind[i] == 0) {
            q.push(i);
            vis[i] = 1;
        }
    }
    vector<int> st;
    while (!q.empty()) {
        int curr = q.front();
        st.push_back(curr);
        q.pop();
        for (auto child : g[curr]) {
            ind[child]--;
            if (ind[child] == 0) {
                q.push(child);
                vis[child] = 1;
            }
        }
    }
};

// Find the center of the tree or Min Height Trees
// Tree has min height if the root is center of the tree.
vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    if (n == 1) {
        return {0};
    }
    vector<vector<int>> g(n);
    vector<int> deg(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int u = edges[i][0], v = edges[i][1];
        g[u].push_back(v), g[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    // Just removing the leaf nodes one by one using queue
    // Possible if diameter length:
    // is odd -----> 1 node
    // is even-----> 2 nodes
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 1) {
            q.push(i);
        }
    }
    while (n > 2) {
        int sz = q.size();
        n -= sz;
        while (sz--) {
            int src = q.front();
            q.pop();
            for (auto ch : g[src]) {
                deg[ch]--;
                if (deg[ch] == 1) {
                    q.push(ch);
                }
            }
        }
    }
    vector<int> ans;
    while (q.size()) {
        int val = q.front();
        ans.push_back(val);
        q.pop();
    }
    return ans;
}
