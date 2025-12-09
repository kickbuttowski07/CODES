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

// bridges and Articulation Point
// for loop dfs for forest
// adjust the size of container so that TLE dont occur

// Formal Defination    
/*Let's say we are in the DFS, looking through the edges starting from vertex v . 
The current edge (v, to) is a bridge if and only if none of the vertices "to" and its descendants 
in the DFS traversal tree has a back-edge to vertex v or any of its ancestors.
Indeed, this condition means that there is no other way from  "v" to "to" except for edge (v, to) .*/

// ### DFS Edge Classification

// - `visited[to] = false` → the edge is **part of the DFS tree**  
// - `visited[to] = true && to ≠ parent` → the edge is a **back edge** to one of the ancestors  
// - `to = parent` → the edge leads back to the **parent** in the DFS tree

// The end points of an bridge will be articulation point if the node has degree of >=2
// an articulation point may exist without bridge

vector<vector<int>> g;
vector<pair<int, int>> vp;
vector<int> tin, low;
vector<char> vis;
int t = 0;
function<void(int, int)> dfs = [&](int src, int par) -> void {
    vis[src] = true;
    tin[src] = low[src] = t++;
    bool parent_skip = false;
    int child = 0;
    for(auto ch : g[src]) {
        if(par == ch && !parent_skip) {
            // avoids treating the parent as a back edge
            parent_skip = true;
            continue;
        }
        if(vis[ch]) {
            // Back edge
            low[src] = min(low[src], tin[ch]);
        }
        else{
            // direct edge or Tree edge
            dfs(ch, src);
            low[src] = min(low[src], low[ch]);
            if(tin[src] < low[ch]) {
                // {src, ch} -> bridge
            }
            if(tin[src] <= low[ch] && par != -1) {
                // src -> cutpoint
            }
            child++;
        }
    }
    if(par == -1 && child > 0) {
        // src -> cutpoint
    }
};



// The existence of Eulerian paths and circuits depends on the degrees of the nodes.
//  First, an undirected graph has an Eulerian path exactly when all the edges
//  belong to the same connected component and
//  • the degree of each node is even or
//  • the degree of exactly two nodes is odd, and the degree of all other nodes is even.
//  In the first case, each Eulerian path is also an Eulerian circuit. 
//  In the second case, the odd-degree nodes are the starting and ending nodes of an Eulerian path
//  which is not an Eulerian circuit. ((odd-deg > in-deg) -> start)

// conditions for euler path or cycle:
// int start_nodes = 0, end_nodes = 0;
// int st = 0;
// for (int i = 0; i < n; i++) {
//     if (odeg[i] - ideg[i] == 1) {
//         start_nodes++;
//         st = i;
//     } else if (ideg[i] - odeg[i] == 1) {
//         end_nodes++;
//     } else if (ideg[i] != odeg[i]) {
//         cout << "IMPOSSIBLE\n";
//         return;
//     }
// }

// if (!((start_nodes == 1 && end_nodes == 1) || (start_nodes == 0 && end_nodes == 0))) {
//     cout << "IMPOSSIBLE\n";
//     return;


// Hierholzer’s algorithm (Eulerian path).
// vector<int> path, stk;
// stk.push_back(st);
// while (!stk.empty()) {
//     int u = stk.back();
//     if (!g[u].empty()) {
//         int v = g[u].rbegin();
//         g[u].erase();
//         if(g[v].count(u)) { // undirected, also need to travel each street once only
//             g[v].erase(u);
//         }
//         stk.push_back(v);
//     } else {
//         path.push_back(u);
//         stk.pop_back();
//     }
// }


// Knight Tour:
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2,  2,  1, -1, -2, -2, -1};

bool isValid(int x, int y, vector<vector<int>>& board) {
    return (x >= 0 && x < N && y >= 0 && y < N && board[x][y] == -1);
}

int degree(int x, int y, vector<vector<int>>& board) {
    int cnt = 0;
    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (isValid(nx, ny, board)) cnt++;
    }
    return cnt;
}

bool solveKT(int x, int y, int movei, vector<vector<int>>& board) {
    if (movei == N * N) return true;

    vector<array<int,3>> cand; // {deg, nx, ny}
    for (int k = 0; k < 8; k++) {
        int nx = x + dx[k], ny = y + dy[k];
        if (isValid(nx, ny, board)) {
            cand.push_back({degree(nx, ny, board), nx, ny});
        }
    }
    sort(all(cand)); // try least degree first

    for (auto it : cand) {
        int d = it[0], nx = it[1], ny = it[2];
        board[nx][ny] = movei;
        if (solveKT(nx, ny, movei + 1, board)) return true;
        board[nx][ny] = -1; // backtrack
    }
    return false;
}