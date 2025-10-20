// always use the vis vector to check instead of thinking greedy to not waste memory
// if graph is acyclic then only use par attribute else use bool array only if not it leads to tle
// *****need to run bfs from all nodes cause the cycle can start from any where it self for shortest, longest cycle
// Graph example:
// 6
// 1 2
// 1 3
// 4 5
// 5 6
// 1 4
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

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// In generally there are connected components in the graph
// so traverse each component
// for each test case for loop N need to clear all the stuffs used in prev test case
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
// is dfs_bipartite or not.....................
// Properties:
// Vertices can be divided into two disjoint sets : A bipartite graph can be partitioned into two sets of vertices, with no edges between vertices within each set.
// Every edge connects vertices in different sets : Every edge in a bipartite graph connects a vertex from one set to a vertex from the other set.
// No odd - length cycles : A bipartite graph cannot contain any odd - length cycles, as this would require vertices from the same set to be connected by an edge.
// Maximum degree is bounded by the size of the smaller set : The maximum degree of a vertex in a bipartite graph is equal to the size of the smaller set.
// Coloring with two colors : A bipartite graph can be colored with two colors, such that no adjacent vertices have the same color.
vector<vector<int>> g;
vector<int> color;
vector<bool> vis;
// vll cnt[2];// check which are the sets
function<bool(int, int)> dfs_bipartite = [&](int par, int col) -> bool {
    color[par] = col;
    for (auto ch : g[par]) {
        if (color[ch] == -1) {
            if (!dfs_bipartite(ch, col ^ 1)) {
                return false;
            }
        }
        else if (color[ch] == col) {
            return false;
        }
    }
    return true;
};

function<bool(int)> bfs_bipartite = [&](int src) -> bool
{
    // O(V + E)
    bool bi = 1;
    vector<int> side(N + 1, -1);

    queue<int> q;
    q.push(src);
    side[src] = 0;
    while (!q.empty())
    {
        int src = q.front();
        q.pop();
        for (auto ch : g[src])
        {
            if (side[ch] == -1)
            {
                side[ch] = side[src] ^ 1;
                q.push(ch);
            }
            else
            {
                bi &= (side[ch] != side[src]);
            }
        }
    }
    return bi;
}; // use the loop

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

// dfs_cycle for directed graph....................O(m) time complexity
// if st == -1, the graph is acyclic
vector<vector<int>> g;
int st = -1, ed = -1;
vector<int> col, par;
function<bool(int)> dfs_cycle = [&](int src) -> bool{
    col[src] = 1;   // when entered it is colored 1
    for(auto ch: g[src]){
        if(col[ch] == 0){
            par[ch] = src;
            if(dfs_cycle(ch)){
                return true;
            }
        }
        else if(col[ch] == 1){
            st = ch, ed = src; // the cycle 
            return true;
        }
    }
    col[src] = 2; // when exited colored 2
    return false;
};
// for (int i = 0; i < n;i++){
//     if(!col[i] && dfs_cycle(i)){
//         break;
//     }
// }

// vector<int>ans;
// ans.pb(st); for(int v = ed; v != st; v = par[v]) { ans.pb(v); } ans.pb(st);
// ----------------------------------------------------------
// Undirected graph:
int st = -1, ed = -1;
vector<int> vis, p;
function<bool(int, int)> dfs = [&](int src, int par) -> bool {
    vis[src] = 1;
    for(auto ch: g[src]) {
        if(!vis[ch]){
            p[ch] = src;
            if(dfs(ch, src)){
                return true;
            }
        }
        else if(par != ch){
            st = ch, ed = src;
            return true;
        }
    }
    return false;
};
// for (int i = 0; i < n;i++){
//     if(!vis[i] && dfs(i, -1)){
//         break;
//     }
// }
// dfs_conn_comp for no of connected components
vector<vector<int>> g;
vector<int> vec;
vector<bool> vis;
function<void(int, int)> dfs_conn_comp = [&](int src, int par) -> void {
    vec.push_back(src);
    for (auto child : g[src]) {
        if (par != child) {
            dfs_conn_comp(child, src);
        }
    }
};

// diameter or longest path of the tree
vector<vector<int>> g;
vector<bool> vis;
ll max_node = -1, max_dis = -1;
function<void(int, int)> dfs_diameter = [&](int src, int d) -> void {
    // longest path of the tree is the diameter of the tree
    // diameter finding:
    //           -> choose a arbitrary node as root run dfs, find the farthest node from it
    //           -> clear the vis vec to run the dfs again
    //           -> again find the farthest from the choosen farthest node, the distance is diameter

    vis[src] = true;
    if (d > max_dis) {
        max_dis = d;
        max_node = src;
    }
    for (auto child : g[src]) {
        if (!vis[child]) {
            dfs_diameter(child, d + 1);
        }
    }
};

// in_time and out time -> euler path
vector<vector<int>> g;
vector<int> in_time, out_time;
ll timer = 1;
function<void(int, int)> euler_path = [&](int src, int par) -> void {
    in_time[src] = timer++;
    for (auto child : g[src]) {
        if (par != child) {
            euler_path(child, src);
        }
    }
    out_time[src] = timer++;
};

// subtree sizes
vector<vector<int>> g;
vector<int> subtree;
function<void(int, int)> dfs_subtree = [&](int src, int par) -> void {
    subtree[src] = 1;
    for (auto child : g[src]) {
        if (par != child) {
            dfs_subtree(child, src);
            subtree[src] += subtree[child];
        }
    }
};

// dfs_leaves count
vector<vector<int>> g;
vector<int> cn_leaf;
function<void(int, int)> dfs_leaves = [&](int src, int par) -> void
{
    bool chk = 1;
    for (auto child : g[src]) {
        if (par != child) {
            chk = 0;
            dfs_leaves(child, src);
            cn_leaf[src] += cn_leaf[child];
        }
    }
    if (chk) {
        cn_leaf[src] = 1;
    }
};

// for bfs also you have to check the connected components
// bfs traversal
vector<vector<int>> g;
vector<int> dis;
vector<bool> vis;
function<void(int)> bfs_level = [&](int src) -> void {
    // O(E + V);
    queue<int> q;
    q.push(src);
    vis[src] = 1;
    dis[src] = 0;
    while (!q.empty()) {
        int curr_par = q.front();
        q.pop();
        for (auto child : g[curr_par]) {
            if (!vis[child]) {
                q.push(child);
                vis[child] = 1;
                dis[child] = dis[curr_par] + 1;
            }
        }
    }
};

// diameter of the tree
function<pair<int, int>(int)> diameter_nodes = [&](int src) -> pair<int, int>
{
    queue<int> q;
    q.push(src);
    int dis[N + 1];
    memset(dis, -1, sizeof(dis));
    dis[src] = 0;
    while (!q.empty()) {
        int cur_p = q.front();
        q.pop();
        for (auto child : g[cur_p]) {
            if (dis[child] == -1) {
                q.push(child);
                dis[child] = dis[cur_p] + 1;
            }
        }
    }
    int max_dis = 0;
    int max_node;
    for (int i = 1; i < N + 1; i++) {
        if (dis[i] > max_dis) {
            max_dis = dis[i];
            max_node = i;
        }
    }
    return make_pair(max_node, max_dis);
};
pair<int, int> p1 = diameter_nodes(1), p2 = diameter_nodes(p1.first);
int end1 = p1.first, end2 = p2.first;