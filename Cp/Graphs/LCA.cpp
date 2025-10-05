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
        

// we can do binary search on the base of weights, height
// https://leetcode.com/problems/find-weighted-median-node-in-tree/description/?envType=problem-list-v2&envId=tree
                                    
inline void solve() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> g(n);

	for (int i = 0; i < n - 1; i++){
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u].pb(v), g[v].pb(u);
	}

	int MAXB = log2(n) + 1;
    vector<vector<int>> up(n, vector<int>(MAXB, -1));
    vector<int> lvl(n, 0);
    vector<bool> vis(n, false);

    function<void(int, int)> dfs = [&](int src, int p) {
        vis[src] = true;
        up[src][0] = p;

        for (auto ch : g[src]) {
            if (!vis[ch]) {
				lvl[ch] = lvl[src] + 1;
				dfs(ch, src);
			}
        }
    };

    dfs(0, -1);

    for (int p = 1; p < MAXB; p++) {
        for (int i = 0; i < n; i++) {
            if (up[i][p - 1] != -1) {
                up[i][p] = up[up[i][p - 1]][p - 1];
            }
        }
    }

    auto kpar = [&](int src, int kth) {
        for (int j = 0; j < MAXB && src != -1; j++) {
            if (kth & (1 << j)) {
                src = up[src][j];
            }
        }
        return src;
    };




    function<int(int, int)> LCA = [&](int a, int b) -> int {
        if (lvl[a] < lvl[b]) swap(a, b);

        int diff = lvl[a] - lvl[b];
        for (int i = MAXB - 1; i >= 0; i--) {
            if ((diff >> i) & 1) {
                a = up[a][i];
            }
        }

        if (a == b) return a;

        for (int i = MAXB - 1; i >= 0; i--) {
            if (up[a][i] != up[b][i]) {
                a = up[a][i];
                b = up[b][i];
            }
        }
        return up[a][0];
    };
	function<int(int, int)> len = [&](int a, int b) -> int{
		int lca = LCA(a, b);
		return lvl[a] + lvl[b] - 2 * lvl[lca];
	};

	while (q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
		cout << len(a, b) << endl;
	}
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