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
    vector<vector<int>> g;
    vector<int> tin, low;
    vector<bool> vis;
    int t = 0;
    function<void(int, int)> dfs = [&](int u, int p) -> void {
        vis[u] = true;
        tin[u] = low[u] = t++;
        bool par_s = false;
        int cn = 0;
        for(auto v : g[u]) {
            if(!par_s && p == v) {
                par_s = 1;
                continue;
            }
            if(vis[v]) {
                low[u] = min(low[u], tin[v]);
            }
            else {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if(tin[u] < low[v]) {
                    // bridge;
                }
                if(tin[u] <= low[v] && p != -1) {
                    // cut point
                }
                cn++;
            }
        }
        if(p == -1 && cn > 0) {
            // src is cut point
        }
    };
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