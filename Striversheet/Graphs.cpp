// use topo sort type for undirected graph

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
    // cin >> t;
    for(int _ = 1; _ <= t; _++) {
        // cout << "Caso #" << _ << endl;
        solve();
    }
                
    return 0;
}
// JAI SHREE RAM
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// In generally there are connected components in the graph
// so traverse each component
// for each test case for loop N need to clear all the stuffs use din prev test case
// when you are running multiple dfs in single implementation then clear vis before each dfs call

// src------>source node
// child---->child of the source node

// simple dfs
function<void(int)> simple_dfs = [&](int src) -> void
{
    /* Take action on source node after
    entering the vertex */
    vis[src] = 1; //-------->Making the vertex as visited
    for (auto child : g[src])
    {
        // Traversing through all the child nodes of the source node
        /* Take action on the child before
        enterning the child node */
        if (!vis[child])
        {
            /* There is no use of considering the visited nodes again*/
            simple_dfs(child);
            /* Take action on child
            after exiting child node*/
        }
    }
    /* Take action on source node
    before exiting the source node*/
};

function<void(int)> reset = [&](int n) -> void
{
    g.clear();
    g.resize(n + 1);
    vis.resize(n + 1, false);
    dis.resize(n + 1, -1);
};

// is dfs_bipartite or not.....................
vector<vector<int>> g;
vector<int> color;
vector<bool> vis;
// vll cnt[2];// check which are the sets
vector<bool> vis(N);
function<bool(int, int)> dfs_bipartite = [&](int par, int col) -> bool
{
    vis[par] = 1;
    color[par] = col;

    for (auto child : g[par])
    {
        if (!vis[child])
        {
            if (!dfs_bipartite(child, col ^ 1))
            {
                return false;
            }
        }
        else if (color[par] == color[child])
        {
            return false;
        }
    }
    return true;
};

// single source shortest path dfs_sssp.............
vector<vector<int>> g;
vector<int> dis;
vector<bool> vis;
function<void(int, int)> dfs_sssp = [&](int par, int d) -> void
{
    // call as (1,0,dfs_sssp);
    vis[par] = true;
    dis[par] = d;

    for (auto child : g[par])
    {
        if (!vis[child])
        {
            dfs_sssp(child, dis[par] + 1);
        }
    }
};

// dfs_cycle for undirected graph....................
// for directed graph use kahn algorithm 
vector<vector<int>> g;
vector<bool> vis;
function<bool(int, int)> dfs_cycle = [&](int src, int par) -> bool
{
    // call as (1,0,dfs_cycle)
    vis[src] = true;
    for (auto child : g[src])
    {
        if (!vis[child])
        {
            if (dfs_cycle(child, src))
            {
                return true;
            }
        }
        if (par != child)
        {
            return true;
        }
    }
    return false;
};
// for directed
vector<bool> vis, instk;
bool chk = false;
function<void(int)> dfsd = [&](int u) -> void
{
    vis[u] = true;
    instk[u] = true;
    for (int v : g[u])
    {
        if (!vis[v])
        {
            dfsd(v);
        }
        else if (instk[v])
        {
            chk = true;
        }
    }
    instk[u] = false;
};

// dfs_conn_comp for no of connected components
vector<vector<int>> g;
vector<int> vec;
vector<bool> vis;
function<void(int, vector<int> &)> dfs_conn_comp = [&](int src, vector<int> vec) -> void
{
    vis[src] = true;
    vec.push_back(src);
    for (auto child : g[src])
    {
        if (!vis[child])
        {
            dfs_conn_comp(child, vec);
        }
    }
};

// diameter or longest path of the tree
vector<vector<int>> g;
vector<bool> vis;
ll max_node = -1, maxx = -1;
function<void(int, int)> dfs_diameter = [&](int src, int d) -> void
{
    // longest path of the tree is the diameter of the tree
    // diameter finding:
    //           ->choose a arbitrary node as root run dfs, find the farthest node from it
    //           -> clear the vis vec to run the dfs again
    //           ->again find the farthest from the choosen farthest node, the distance is diameter

    vis[src] = true;
    if (d > maxx)
    {
        maxx = d;
        max_node = src;
    }
    for (auto child : g[src])
    {
        if (!vis[child])
        {
            dfs_diameter(child, d + 1);
        }
    }
};

// in_time and out time
vector<vector<int>> g;
vector<int> in_time, out_time;
vector<bool> vis;
ll timer = 1;
function<void(int)> dfs_times = [&](int src) -> void
{
    vis[src] = 1;
    in_time[src] = timer++;
    for (auto child : g[src])
    {
        if (!vis[child])
        {
            dfs_times(child);
        }
    }
    out_time[src] = timer++;
};

// subtree sizes
vector<vector<int>> g;
vector<int> subtree;
vector<bool> vis;
function<void(int)> dfs_subtree = [&](int src) -> void
{
    vis[src] = 1;
    subtree[src] = 1;
    for (auto child : g[src])
    {
        if (!vis[child])
        {
            dfs_subtree(child);
            subtree[src] += subtree[child];
        }
    }
};

// dfs_leaves count
vector<vector<int>> g;
vector<int> cn_leaf;
vector<bool> vis;
function<void(int)> dfs_leaves = [&](int src) -> void
{
    vis[src] = 1;
    bool chk = 1;
    for (auto child : g[src])
    {
        if (!vis[child])
        {
            chk = 0;
            dfs_leaves(child);
            cn_leaf[src] += cn_leaf[child];
        }
    }
    if (chk)
    {
        cn_leaf[src] = 1;
    }
};

// for bfs also you have to check the connected components
// bfs traversal
vector<vector<int>> g;
vector<int> dis;
vector<bool> vis;
function<void(int)> bfs_level = [&](int src) -> void
{
    // O(E + V);
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    dis[src] = 0;
    while (!q.empty())
    {
        int curr_par = q.front();
        q.pop();
        for (auto child : g[curr_par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = 1;
                dis[child] = dis[curr_par] + 1;
            }
        }
    }
};
// In normal the shortest distance from a source can be done if weights are equal is can be done by normal bfs traversal
// Weights are different then Dijkstra Algo is used O(|E|log|V|) OR O(|V|^2 + |E|)
// In dfs tree there are only forward edges and back edges
// back edges can never be bridges

// bridges and Articulation Point
// for loop dfs for forest
// adjust the size of container so that tle dont occur
vector<vector<int>> g;
vector<int> low, in_time;
vector<bool> vis;
vector<pair<int, int>> vp;
ll timer = 1;
auto s_bridge = [&](int u, int v) -> void
{
    vp.push_back({min(u, v), max(u, v)});
    // Do what ever required
};
auto dfs_bridges = [&](int src, int par, auto &&dfs_ref) -> void
{
    // O(E + V);
    vis[src] = 1;
    in_time[src] = low[src] = timer++;
    int children = 0; // for articulation point
    for (auto child : g[src])
    {
        if (child != par)
        {
            if (vis[child])
            {
                // Back edge
                low[src] = min(low[src], in_time[child]);
            }
            else
            {
                dfs_ref(child, src, dfs_ref);
                low[src] = min(low[src], low[child]);
                // for bridge condition
                if (low[child] > in_time[src])
                {
                    is_bridge(src, child);
                }
                // for articulation point condition
                if (low[child] >= intime[src] && par != -1)
                {
                    is_cutpoint(src);
                    // cut vertecx or articulation point
                }
                children++;
            }
        }
    }
    if (p == -1 && children > 1)
    {
        is_cutpoint(src);
        // cut vertecx or articulation point
    }
};

// The end points of an bridge will be articulation point if the node has degree of >=2
// an articulation point may exist without bridge

function<bool(int)> bfs_bipartite = [&](int src) -> bool
{
    // O(V + E)
    queue<int> q;
    q.push(src);
    vis[src] = true;
    color[src] = 1;
    while (!q.empty())
    {
        int curr_par = q.front();
        q.pop();
        for (auto child : g[curr_par])
        {
            if (color[child] == -1)
            {
                color[child] = 1 - color[curr_par];
                vis[child] = true;
                q.push(child);
            }
            else if (color[curr_par] == color[child])
            {
                return false;
            }
        }
    }
    return true;
}; // use the loop

// diameter of the tree
function<pair<int, int>(int)> diameter_nodes = [&](int src) -> pair<int, int>
{
    queue<int> q;
    q.push(src);
    // N= n.....................................
    int dis[N + 1];
    memset(dis, -1, sizeof(dis));
    dis[src] = 0;
    while (!q.empty())
    {
        int cur_p = q.front();
        q.pop();
        for (auto child : g[cur_p])
        {
            if (dis[child] == -1)
            {
                q.push(child);
                dis[child] = dis[cur_p] + 1;
            }
        }
    }
    int maxDis = 0;
    int nodeIdx;
    for (int i = 1; i < N + 1; i++)
    {
        if (dis[i] > maxDis)
        {
            maxDis = dis[i];
            nodeIdx = i;
        }
    }
    return make_pair(nodeIdx, maxDis);
};
pair<int, int> p1 = diameter_nodes(1), p2 = diameter_nodes(p1.first);
int end1 = p1.first, end2 = p2.first;


// Mininum Spanning Trees by kruskal algorithm
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    vector<vector<int>> edges;
    for (int u = 0; u < V; ++u)
    {
        for (auto it : adj[u])
        {
            int v = it[0];
            int weight = it[1];
            if (u < v)
            {
                edges.push_back({weight, u, v});
            }
        }
    }
    sort(edges.begin(), edges.end());
    vector<int> parent(V, -1), rank(V, 1);
    // use DSU instead;
    auto find = [&](int i, auto &&ref) -> int
    {
        if (parent[i] == -1)
            return i;
        return parent[i] = ref(parent[i], ref);
    };
    auto unite = [&](int x, int y) -> void
    {
        int s1 = find(x, find);
        int s2 = find(y, find);

        if (s1 != s2)
        {
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2])
            {
                parent[s2] = s1;
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    };
    int sum = 0;
    for (auto i : edges)
    {
        int x = i[0], y = i[1], z = i[2];
        if (find(y, find) != find(z, find))
        {
            unite(y, z);
            sum += x;
        }
    }
    return sum;
}
// topo_sort
// Only exists in DAG 
// If the nodes of a graph are connected through directed edges and 
// the graph does not contain a cycle, it is called a directed acyclic graph(DAG). 
// Defination: The topological sorting of a directed acyclic graph is nothing but the linear ordering of vertices such that,
// if there is an edge between node u and v(u -> v), node u appears before v in that ordering.
// O(V + E) + O(V), O(2N)

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
auto kahn_alg = [&]() -> vector<int>
{
    for (int u = 0; u < N; u++)
    {
        for (auto v : adj[u])
        {
            g[u].push_back(v);
            ind[v]++;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (ind[i] == 0)
        {
            q.push(i);
            vis[i] = 1;
        }
    }
    vector<int> st;
    while (!q.empty())
    {
        int curr = q.front();
        st.push_back(curr);
        q.pop();
        for (auto child : g[curr])
        {
            ind[child]--;
            if (ind[child] == 0)
            {
                q.push(child);
                vis[child] = 1;
            }
        }
    }
};


// Shortest Path Algorithm in DAG
// do toposort and use the stack as queue and do bfs
// https://takeuforward.org/data-structure/shortest-path-in-directed-acyclic-graph-topological-sort-g-27/


// Dijkstra Algorithm Directed, Undirected
// Not for negative weights, negative cycles
// array of vector<pair<int,int>>
// IN this check the out of bounds condition for distance be careful
vector<pair<int, int>> gr[N]; // to pair of weight, node_to
auto dijkstra_alg = [&](int src) -> vector<int>
{
    // priority queue usage
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(N, INT_MAX);
    vector<bool> vis(N, false);
    pq.push({0, src});
    dis[src] = 0;
    while (!pq.empty())
    {
        int par = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if(vis[par]) {
            continue;
        }
        vis[par] = true;
        for (int i = 0; i < gr[par].size(); i++)
        {
            int w = gr[par][i].second, v = gr[par][i].first;
            if (!vis[v] && (d + w ) < dis[v]){
                dis[v] = d + w;
                pq.push({d + w, v});
            }
        }
    }
    return dis;
};
// Floyd Warshall Algorithm
// for neg cycles, neg weights, directed and undirected
// used adj matrix
auto floyd_warshal = [&](vector<vector<int>> &adj_m) -> void
{
    int n = adj_m.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj_m[i][j] == -1)
            {
                // no edge between node i, j
                adj_m[i][j] = 1e9;
            }
            if (i == j)
            {
                adj_m[i][j] = 0;
            }
        }
    }
    for (int k = 0; k < n; k++)
    {
        // outer one is for intermediate nodes of i, j
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj_m[i][j] = min(adj_m[i][j], adj_m[i][k] + adj_m[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj_m[i][j] == 1e9)
            {
                adj_m[i][j] = -1;
            }
        }
    }
};

// Binary Lifting and LCA
// adjust the 2d vector according to the N value
vector<vector<int>> up(N, vector<int>(20, 0));
vector<int> dp(N, -1);
vector<int> g[N];

void dfs(int v, int par)
{
    dp[v] = dp[par] + 1;
    up[v][0] = par;
    for (int i = 1; i < 20; ++i)
    {
        up[v][i] = up[up[v][i - 1]][i - 1];
    }
    for (auto x : g[v])
    {
        if (x == par)
            continue;
        dfs(x, v);
    }
}

int lca(int a, int b)
{
    if (dp[a] < dp[b])
        swap(a, b);
    int k = dp[a] - dp[b];
    for (int i = 19; i >= 0; --i)
    {
        if (k & (1 << i))
        {
            a = up[a][i];
        }
    }
    if (a == b)
    {
        return a;
    }
    for (int i = 19; i >= 0; --i)
    {
        if (up[a][i] != up[b][i])
        {
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

// Find the center of the tree or Min Height Trees
// Tree has min height if the root is center of the tree.
vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    if (n == 1)
    {
        return {0};
    }
    vector<vector<int>> g(n);
    vector<int> deg(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int u = edges[i][0], v = edges[i][1];
        g[u].push_back(v), g[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    // Just removing the leaf nodes one by one using queue
    // Possible if diameter length:
    // is odd -----> 1 node
    // is even-----> 2 nodes
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (deg[i] == 1)
        {
            q.push(i);
        }
    }
    while (n > 2)
    {
        int sz = q.size();
        n -= sz;
        while (sz--)
        {
            int src = q.front();
            q.pop();
            for (auto ch : g[src])
            {
                deg[ch]--;
                if (deg[ch] == 1)
                {
                    q.push(ch);
                }
            }
        }
    }
    vector<int> ans;
    while (q.size())
    {
        int val = q.front();
        ans.push_back(val);
        q.pop();
    }
    return ans;
}

