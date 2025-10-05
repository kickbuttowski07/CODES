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
        

long long rng() {
    static std::mt19937 gen(std::chrono::steady_clock::now().time_since_epoch().count());
    return std::uniform_int_distribution<long long>(0, INT64_MAX)(gen);
}
// XOR Hashing/Zobrist Hashing
// https://usaco.guide/gold/hashing#string-hashing
                                    
inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    for (int i = 0; i < n;i++){
        cin >> b[i];
    }

    map<int, int> hsh;
    vector<int> xa(n), xb(n);

    for (int i = 0; i < n;i++){
        if(!hsh.count(a[i])){
            hsh[a[i]] = rng();
        }
    }

    for (int i = 0; i < n;i++){
        if(!hsh.count(b[i])){
            hsh[b[i]] = rng();
        }
    }

    set<int> st;
    for (int i = 0; i < n;i++){
        if(!st.count(a[i])){
            xa[i] = hsh[a[i]];
            st.insert(a[i]);
        }
        if(i > 0){
            xa[i] ^= xa[i - 1];
        }
    }
    st.clear();
    for (int i = 0; i < n;i++){
        if(!st.count(b[i])){
            xb[i] = hsh[b[i]];
            st.insert(b[i]);
        }
        if(i > 0){
            xb[i] ^= xb[i - 1];
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q;i++){
        int l, r;
        cin >> l >> r;
        l--, r--;
        string ans = (xa[l] == xb[r]) ? "Yes" : "No";
        cout << ans << endl;
    }
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