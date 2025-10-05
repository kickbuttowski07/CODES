#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1, MOD = (int)(1e9 + 7);
#define int long long
#define ll long long
#define forl(i, a, b, k) for (ll i = a; i < b; i += k)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define pb push_back
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
// a.order_of_key(x)-----gives no of elements less than that number
// a.find_by_order(k)---kth element starting from 0
// ordered_multiset lower bound -> -1, upper bound -> INT_MAX
// multiset key should be pair
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
        if(t) {
            cout << endl;
        }
    }
                
    return 0;
}
// JAI SHREE RAM
// Do learn about ordered_multiset order_of_key and find_by_order