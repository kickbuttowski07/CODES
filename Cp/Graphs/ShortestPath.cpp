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

int n, m, u, v, w;


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

//Bellman Ford:
// If given undirected make it directed by making 2 directed edges with the same weight for each direction
// Properties:
// finds whether if any -ve weighted edge cycle is reachable from the source, not always detect the -ve weighted edge cycle.
// Reason why V-1 times: A shortest path between two vertices can have at most (V - 1) edges. 
// It is not possible to have a simple path with more than (V - 1) edges (otherwise it would form a cycle). 
// Therefore, repeating the relaxation process (V - 1) times ensures that all possible paths between source and any other node have been covered.
vector<tuple<int, int, int>> g(m);
function<vector<int>(int)> Bellman = [&](int src) -> vector<int> {
    vector<int> dis(n, 1e8);
    dis[src] = 0;
    for (int i = 0; i < n; i++) {
        for (auto tp : g) {
            tie(u, v, w) = tp;
            if (dis[u] != 1e8 && dis[v] > dis[u] + w) {
                if (i == n - 1)
                {
                    return {-1}; // Negative Cycle if relaxation is happening in nth iteration then it has -ve cycle, since have atmost n-1 edges of shortest path 
                }
                dis[v] = dis[u] + w; // Relaxation or Updating
            }
        }
    }
    return dis;
};



// Shortest Path Algorithm in DAG
// do toposort and use the stack as queue and do bfs
// Implementation:
// vector<int> dist(n, LLONG_MIN);
// dist[src] = 0; -> from which node u need shortest path

// for (int u : topo) {
//     if (dist[u] == -INF) continue; // not reachable
//     for (auto [v, w] : g[u]) {
//         dist[v] = max(dist[v], dist[u] + w);
//     }
// }
// https://takeuforward.org/data-structure/shortest-path-in-directed-acyclic-graph-topological-sort-g-27/


// Dijkstra Algorithm Directed, Undirected
// Not for negative weights, negative cycles
// array of vector<pair<int,int>>
// IN this check the out of bounds condition for distance be careful

// It's important to include continue. (with dis condition is better)
// This ensures that when all edge weights are non-negative, we will never go through the adjacency list of any vertex more than once. 
// Removing it will cause TLE on the last test case of the above problem!

// Time complexity = (E log V) (VlogV(delete node) + ElogV(update))

vector<pair<int, int>> gr[N]; // to pair of weight, node_to
auto dijkstra_alg = [&](int src) -> vector<int>
{
    // priority queue usage
    using T = pair<int, int>;
    priority_queue<T, vector<T>, greater<T>> pq;
    vector<int> dis(N, LLONG_MAX);
    pq.push({0, src});
    dis[src] = 0;
    while (!pq.empty()) {
        int src = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dis[src]) { 
            continue; 
        } 
        for (int i = 0; i < gr[src].size(); i++) {
            int w = gr[src][i].second, ch = gr[src][i].first;
            if ((d + w) < dis[ch]){
                dis[ch] = d + w;
                pq.push({d + w, ch});
            }
        }
    }
    return dis;
};
// Floyd Warshall Algorithm
// for detection of neg cycles,and shortest path in case of neg weights, directed and undirected
// Not for neg cycles
// used adj matrix
auto floyd_warshal = [&](void) -> void
{
    vector<vector<int>> g(n, vector<int>(n, -1));
    for (int i = 0; i < m;i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        if(g[u][v] == -1){
            g[u][v] = g[v][u] = w;
        }
        else{
            g[u][v] = g[v][u] = min(w, g[u][v]); // minimise initially only
        }
    }
    int dis[n][n];
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(i == j){
                dis[i][j] = 0;
            }
            else{
                if(g[i][j] < 0){
                    dis[i][j] = 1e18;
                }
                else{
                    dis[i][j] = g[i][j];
                }
            }
        }
    }

    for (int k = 0; k < n;k++){
        for (int i = 0; i < n;i++){
            for (int j = i + 1; j < n;j++){
                int new_dist = dis[i][k] + dis[k][j];
				if (new_dist < dis[i][j]) {
					dis[i][j] = dis[j][i] = new_dist;
				}
            }
        }
    }

    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(dis[i][j] >= 1e18){
                dis[i][j] = -1;
            }
        }
    }
};

// https://codeforces.com/contest/1063/problem/B
// 0-1 BFS
// Imp notes is that here the edge waits are (0, 1) according to that we push front or back
// Do 0-1 BFS similar to dijkstra, also do relaxation with similar conditions
// In general do in 2d matrix movements shortest distance to reach with constraints
// vector<int> dis(n, LLONG_MAX);
// dis[s] = 0;
// deque<int> q;
// q.push_front(s);
// while (!q.empty()) {
//     int v = q.front();
//     q.pop_front();
//     for (auto edge : adj[v]) {
//         int u = edge.first;
//         int w = edge.second;
//         if (dis[v] + w < dis[u]) {
//             dis[u] = dis[v] + w;
//             // to maintain sorted list of queue
//             if (w == 1)
//                 q.push_back(u);
//             else
//                 q.push_front(u);
//         }
//     }
// }



/*
    Dial’s Algorithm Template
    -------------------------
    - Works for graphs with non-negative integer edge weights
    - Time: O(V + E + W) where W = maximum edge weight
    - Space: O(V + E)
*/

// Dijkstra’s algorithm can be modified by using different data structures, and buckets, which is called dial implementation of Dijkstra's algorithm. 
// time complexity is O(E + WV) where W is the maximum weight on any edge of the graph. 
// so we can see that, if W is small then this implementation runs much faster than the traditional algorithm. 

struct Dial {
    int n, maxW;  // number of nodes, maximum edge weight
    vector<vector<pair<int,int>>> adj; // adjacency list: {neighbor, weight}
    vector<int> dist; // shortest distances

    Dial(int n, int maxW) : n(n), maxW(maxW) {
        adj.assign(n, {});
        dist.assign(n, LLONG_MAX);
    }

    void addEdge(int u, int v, int w, bool undirected = true) {
        adj[u].push_back({v, w});
        if (undirected) adj[v].push_back({u, w});
    }

    vector<int> run(int src) {
        dist.assign(n, LLONG_MAX);
        dist[src] = 0;

        int maxDist = (n - 1) * maxW;
        vector<unordered_set<int>> buckets(maxDist + 1);
        buckets[0].insert(src);

        for (int d = 0; d <= maxDist; d++) {  // check upto max distance
            while (!buckets[d].empty()) {
                int u = *buckets[d].begin();
                buckets[d].erase(buckets[d].begin());

                if (d > dist[u]) continue;

                for (auto [v, w] : adj[u]) {
                    int newDist = dist[u] + w;
                    if (newDist < dist[v]) {
                        if (dist[v] != LLONG_MAX)
                            buckets[dist[v]].erase(v);

                        dist[v] = newDist;
                        buckets[newDist].insert(v);
                    }
                }
            }
        }
        return dist;
    }
};
