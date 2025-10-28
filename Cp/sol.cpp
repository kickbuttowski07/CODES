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

class PalinHash{
    static const int p = 131;
    static const int MOD = 1595061967;
    vector<int> hsh, rhsh;
    vector<int> pw;
    int n;

public:
    PalinHash(const string &s) {
        this->n = s.size();
        this->hsh = vector<int>(n + 1, 0);
        this->rhsh = vector<int>(n + 1, 0);
        this->pw = vector<int>(n + 1, 1);
        for (int i = 1; i <= n;i++) {
            hsh[i] = (1LL * hsh[i - 1] * p + s[i - 1]) % MOD;
            pw[i] = (1LL * pw[i - 1] * p) % MOD;
        }

        for (int i = n - 1; i >= 0;i--) {
            rhsh[i] = (1LL * rhsh[i + 1] * p + s[i]) % MOD;
        }
    }

    int hash_value(int l, int r) {
        return (hsh[r + 1] - 1LL * hsh[l] * pw[r - l + 1] % MOD + MOD) % MOD;
    }

    int reverse_hash_value(int l, int r) {
        return (rhsh[l] - 1LL * rhsh[r + 1] * pw[r - l + 1] % MOD + MOD) % MOD;
    }

    bool is_palindrome(int l, int r) {
        return hash_value(l, r) == reverse_hash_value(l, r);
    }
};

vector<int>pref(const string s) {
    int n = s.size();
    vector<int> pi(n);
    for (int i = 1; i < n;i++) {
        int j = pi[i - 1];
        while(j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if(s[i] == s[j]) {
            j++;
        }
        pi[i] = j;
    }
    return pi;
}

vector<int>zfunc(const string s) {
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n;i++) {
        z[i] = max(0LL, min(z[i - l], r - i + 1));
        while(i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            l = i, r = i + z[i];
            z[i]++;
        }
    }
    return z;
}

inline void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n + 1, 0);
    PalinHash ph(s);
    int a, b;
    cin >> a >> b;
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