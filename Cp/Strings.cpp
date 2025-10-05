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

template<typename T = char>
class StringHasher1 {
public:
    static const int p = 131;
    static const int MOD = 1595061967;

    vector<int> hsh, pw;
    int n;

    StringHasher1(const string& s) {
        n = s.size();
        hsh.resize(n + 1, 0);
        pw.resize(n + 1, 1);
        // hsh -> {0, s[0], s[0]*p + s[1], s[0]*p^2 + s[1]*p + s[2],.....}
        // hsh[i] = 0 (i == 0)
        // hsh[i] = hsh[i - 1] * p + s[i - 1] (i > 0)
        for (int i = 1; i <= n; i++) {
            hsh[i] = (1LL * hsh[i - 1] * p + s[i - 1]) % MOD;
            pw[i] = 1LL * pw[i - 1] * p % MOD;
        }
    }

    int hash_value(int l, int r) { // hash_value [l,,,,r]   so from l to r
        return (hsh[r + 1] - 1LL * hsh[l] * pw[r - l + 1] % MOD + MOD) % MOD;
    }
};

// Number Hasher
template<typename T = int>
class NumberHasher {
public:
    // two bases & two mods
    static const int p1 = 131;
    static const int p2 = 137;
    static const int MOD1 = 1000000007;
    static const int MOD2 = 1000000009;

    vector<int> hsh1, hsh2, pw1, pw2;
    int n;

    NumberHasher(const vector<T>& a) {
        n = a.size();
        hsh1.resize(n + 1, 0);
        hsh2.resize(n + 1, 0);
        pw1.resize(n + 1, 1);
        pw2.resize(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            hsh1[i] = (1LL * hsh1[i - 1] * p1 + (a[i - 1] + 1)) % MOD1;
            hsh2[i] = (1LL * hsh2[i - 1] * p2 + (a[i - 1] + 1)) % MOD2;
            pw1[i] = 1LL * pw1[i - 1] * p1 % MOD1;
            pw2[i] = 1LL * pw2[i - 1] * p2 % MOD2;
        }
    }

    // return 64-bit combined hash for subarray [l, r]
    long long hash_value(int l, int r) {
        int hv1 = (hsh1[r + 1] - 1LL * hsh1[l] * pw1[r - l + 1] % MOD1 + MOD1) % MOD1;
        int hv2 = (hsh2[r + 1] - 1LL * hsh2[l] * pw2[r - l + 1] % MOD2 + MOD2) % MOD2;
        return (1LL * hv1 << 32) ^ hv2; // combine safely
    }
};


const ll mod1 = 1000000007;
const ll mod2 = 1000000009;
const ll base1 = 911382323;
const ll base2 = 972663749;

vector<ll> pw1, pw2;

void init_pow(int n) {
    pw1.resize(n + 1);
    pw2.resize(n + 1);
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i <= n; i++) {
        pw1[i] = (pw1[i - 1] * base1) % mod1;
        pw2[i] = (pw2[i - 1] * base2) % mod2;
    }
}

pair<vector<ll>, vector<ll>> build(vector<int>& a) {
    int n = a.size();
    vector<ll> pref1(n + 1), pref2(n + 1);
    for (int i = 0; i < n; i++) {
        pref1[i + 1] = (pref1[i] * base1 + (a[i] + 1)) % mod1;
        pref2[i + 1] = (pref2[i] * base2 + (a[i] + 1)) % mod2;
    }
    return {pref1, pref2};
}

// return combined 64-bit key
ll get_hash(const vector<ll>& pref1, const vector<ll>& pref2, int l, int r) {
    ll h1 = (pref1[r + 1] - (pref1[l] * pw1[r - l + 1]) % mod1 + mod1) % mod1;
    ll h2 = (pref2[r + 1] - (pref2[l] * pw2[r - l + 1]) % mod2 + mod2) % mod2;
    return (h1 << 32) ^ h2; // combine safely
}



template<typename T = char>
class PalinHash {
public:
    static const int p = 131;
    static const int MOD = 1595061967;
    // static const int p1 = 131;
    // static const int p2 = 137;
    // static const int MOD1 = 1000000007;
    // static const int MOD2 = 1000000009;

    vector<int> hsh, pw, rhsh;
    int n;

    PalinHash(const string& s) {
        n = s.size();
        hsh.resize(n + 1, 0);
        rhsh.resize(n + 1, 0);
        pw.resize(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            hsh[i] = (1LL * hsh[i - 1] * p + s[i - 1]) % MOD;
            pw[i] = 1LL * pw[i - 1] * p % MOD;
        }

        for (int i = n - 1; i >= 0; i--) {
            rhsh[i] = (1LL * rhsh[i + 1] * p + s[i]) % MOD;
        }
    }

    int hash_value(int l, int r) { // hash_value [l,,,,r]   so from l to r
        return (hsh[r + 1] - 1LL * hsh[l] * pw[r - l + 1] % MOD + MOD) % MOD;
    }

    int reverse_hash_value(int l, int r) { // [l,,,,r] so from l to r
        return (rhsh[l] - 1LL * rhsh[r + 1] * pw[r - l + 1] % MOD + MOD) % MOD;
    }

    bool is_palindrome(int l, int r) {
        return hash_value(l, r) == reverse_hash_value(l, r);
    }
};


template<typename T = char>
class StringHasher2 {
public:
    static const int p1 = 131, p2 = 137;
    static const int MOD1 = 1595061967, MOD2 = 1998320353;

    vector<int> hsh1, hsh2, pw1, pw2;
    vector<int> rhsh1, rhsh2;
    int n;

    StringHasher2(const string& s) {
        n = s.size();
        hsh1.resize(n + 1, 0);
        hsh2.resize(n + 1, 0);
        pw1.resize(n + 1, 1);
        pw2.resize(n + 1, 1);
        rhsh1.resize(n + 1, 0);
        rhsh2.resize(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            hsh1[i] = (1LL * hsh1[i - 1] * p1 + s[i - 1]) % MOD1;
            pw1[i] = 1LL * pw1[i - 1] * p1 % MOD1;
            hsh2[i] = (1LL * hsh2[i - 1] * p2 + s[i - 1]) % MOD2;
            pw2[i] = 1LL * pw2[i - 1] * p2 % MOD2;
        }

        for (int i = n - 1; i >= 0; i--) {
            rhsh1[i] = (1LL * rhsh1[i + 1] * p1 + s[i]) % MOD1;
            rhsh2[i] = (1LL * rhsh2[i + 1] * p2 + s[i]) % MOD2;
        }
    }

    pair<int, int> hash_pair(int l, int r) {
        int hash1 = (hsh1[r + 1] - 1LL * hsh1[l] * pw1[r - l + 1] % MOD1 + MOD1) % MOD1;
        int hash2 = (hsh2[r + 1] - 1LL * hsh2[l] * pw2[r - l + 1] % MOD2 + MOD2) % MOD2;
        return {hash1, hash2};
    }

    ll hash_value(int l, int r) {
        int hash1 = (hsh1[r + 1] - 1LL * hsh1[l] * pw1[r - l + 1] % MOD1 + MOD1) % MOD1;
        int hash2 = (hsh2[r + 1] - 1LL * hsh2[l] * pw2[r - l + 1] % MOD2 + MOD2) % MOD2;
        return (1LL * hash1 << 32) | hash2;
    }

    pair<int, int> reverse_hash_pair(int l, int r) {
        int hash1 = (rhsh1[l] - 1LL * rhsh1[r + 1] * pw1[r - l + 1] % MOD1 + MOD1) % MOD1;
        int hash2 = (rhsh2[l] - 1LL * rhsh2[r + 1] * pw2[r - l + 1] % MOD2 + MOD2) % MOD2;
        return {hash1, hash2};
    }

    ll reverse_hash_value(int l, int r) {
        int hash1 = (rhsh1[l] - 1LL * rhsh1[r + 1] * pw1[r - l + 1] % MOD1 + MOD1) % MOD1;
        int hash2 = (rhsh2[l] - 1LL * rhsh2[r + 1] * pw2[r - l + 1] % MOD2 + MOD2) % MOD2;
        return (1LL * hash1 << 32) | hash2;
    }
};



                                    
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
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// KMP Algorithm and pattern matching using Pref function
// Need to refer in gfg about all the cases
// USE of KMP Algorithm and Prefix Function:

/*The idea is to choose a character ($ or #) which is not present in any of the string p and t,
which acts as a separator. Compute the prefix function for the string p + # + t.
Notice the value of the prefix function at any index will not exceed n because of the separator.
Now if π[i] = n at any position i, that means a match is found, i.e., occurrence of pattern p in text t.
Notice the π[i] = n won’t be true for first n + 1 positions in the prefix function since it belongs to pattern p and separator #.
Hence we take all positions where π[i] = n after the n + 1 position as matches of p in t.*/
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// distinct subtrings in a string using hashing, 2 bases, 2 mods
//  probability of two random strings colliding is about 1/(p^2) where p is the base
//  so we can use two bases and two mods to avoid collision
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// z_function:
// The Z-array z of a string s of length n contains for each k = 0,1,...,n - 1 the
// length of the longest substring of s that begins at position k and is a prefix of string s. 
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n;i++){
        z[i] = max(0ll, min(z[i - l], r - i + 1));
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
            l = i, r = i + z[i];
            z[i]++;
        }
    }
    return z;
}
// prefix function :The prefix function for a string s is an array 
// π, where π[i] is the length of the longest proper prefix of the substring s[0...i]    
// which is also a suffix of this substring.
// Proper Prefix: A prefix of a string that is not equal to the string itself.
// Knuth–Morris–Pratt (KMP) Algorithm is a linear time string searching algorithm that efficiently 
// finds occurrences of a pattern within a text. 

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// Manacher's Algorithm
vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 0, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = min(r - i, p[l + (r - i)]);
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

