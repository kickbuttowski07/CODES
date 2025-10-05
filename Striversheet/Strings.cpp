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
class PalinHash {
public:
    static const int p = 131;
    static const int MOD = 1595061967;

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

    int hash_value(int l, int r) {
        return (hsh[r] - 1LL * hsh[l] * pw[r - l] % MOD + MOD) % MOD;
    }

    int reverse_hash_value(int l, int r) {
        return (rhsh[l] - 1LL * rhsh[r + 1] * pw[r - l + 1] % MOD + MOD) % MOD;
    }

    bool is_palindrome(int l, int r) {
        return hash_value(l, r) == reverse_hash_value(l, r);
    }
};


template<typename T = char>
class StringHasher {
public:
    static const int p1 = 131, p2 = 137;
    static const int MOD1 = 1595061967, MOD2 = 1998320353;

    vector<int> hsh1, hsh2, pw1, pw2;
    vector<int> rhsh1, rhsh2;
    int n;

    StringHasher(const string& s) {
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

    int hash_value(int l, int r) {
        int hash1 = (hsh1[r + 1] - 1LL * hsh1[l] * pw1[r - l + 1] % MOD1 + MOD1) % MOD1;
        int hash2 = (hsh2[r + 1] - 1LL * hsh2[l] * pw2[r - l + 1] % MOD2 + MOD2) % MOD2;
        return (1LL * hash1 << 32) | hash2;
    }

    pair<int, int> reverse_hash_pair(int l, int r) {
        int hash1 = (rhsh1[l] - 1LL * rhsh1[r + 1] * pw1[r - l + 1] % MOD1 + MOD1) % MOD1;
        int hash2 = (rhsh2[l] - 1LL * rhsh2[r + 1] * pw2[r - l + 1] % MOD2 + MOD2) % MOD2;
        return {hash1, hash2};
    }

    int reverse_hash_value(int l, int r) {
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
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// to avoid the collision betwwen the strings
// collision is a thing which having same hash value for both different strings to avoid this we use the different mods, bases
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1, MOD = 1000000007;
#define ll long long
#define vll vector<ll>
#define forl(i, a, b, k) for (ll i = a; i < b; i += k)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
const int p1 = 131, p2 = 137, MOD1 = 1595061967, MOD2 = 1998320353;
vll hsh, hsh2, pw, pw2;
inline void solve()
{
    string a, b;
    cin >> a >> b;
    ll n = a.size(), m = b.size();
    hsh.resize(m + 1, 0);
    hsh2.resize(m + 1, 0);
    pw.resize(m + 1, 1);
    pw2.resize(m + 1, 1);
    vll freq_a(26), freq_b(26);
    for (int i = 0; i < n; i++)
    {
        freq_a[a[i] - 'a']++;
    }
    for (int i = 1; i <= m; i++)
    {
        hsh[i] = (hsh[i - 1] * p1 + b[i - 1]) % MOD1;
        pw[i] = pw[i - 1] * p1 % MOD1;
        hsh2[i] = (hsh2[i - 1] * p2 + b[i - 1]) % MOD2;
        pw2[i] = pw2[i - 1] * p2 % MOD2;
    }
    function<ll(ll, ll)> hash_substring = [&](ll l, ll r) -> ll
    {
        ll h1 = (hsh[r] - hsh[l + 1] * pw[r - l - 1] % MOD1 + MOD1) % MOD1;
        ll h2 = (hsh2[r] - hsh2[l + 1] * pw2[r - l - 1] % MOD2 + MOD2) % MOD2;
        return (h1 << 32) | h2;
    };
    set<ll> st;
    for (int i = 1; i <= m; i++)
    {
        freq_b[b[i - 1] - 'a']++;
        if (i > n)
            freq_b[b[i - n - 1] - 'a']--;
        if (freq_a == freq_b) {
            st.insert(hash_substring(i - n - 1, i));
        }
    }
    cout << st.size() << endl;
}

signed main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1, MOD = 1000000007;
#define ll long long
#define vll vector<ll>
#define forl(i, a, b, k) for (ll i = a; i < b; i += k)
#define Sort(a) sort(a.begin(), a.end());
// KMP Algorithm and pattern matching using Pref function
// Need to refer in gfg about all the cases
// USE of KMP Algorithm and Prefix Function:

/*The idea is to choose a character ($ or #) which is not present in any of the string p and t,
which acts as a separator. Compute the prefix function for the string p + # + t.
Notice the value of the prefix function at any index will not exceed n because of the separator.
Now if π[i] = n at any position i, that means a match is found, i.e., occurrence of pattern p in text t.
Notice the π[i] = n won’t be true for first n + 1 positions in the prefix function since it belongs to pattern p and separator #.
Hence we take all positions where π[i] = n after the n + 1 position as matches of p in t.*/

inline void solve()
{
    string pat, txt;
    cin >> pat >> txt;

    auto pref_func = [&](string &s) -> vector<int>
    {
        // O(n) apprarch
        int n = (int)s.length();
        vector<int> pi(n);

        for (int i = 1; i < n; i++)
        {
            int j = pi[i - 1];
            while (j > 0 && s[i] != s[j])
            {
                j = pi[j - 1];
            }
            if (s[i] == s[j])
            {
                j++;
            }
            pi[i] = j;
        }

        return pi;
    };

    // Example pat = abc, txt = ababcababcabc
    string curr = pat + '#' + txt; // size = n+m+1
    vector<int> pref = pref_func(curr);
    vector<int> pos_of_occurences;
    int n = pat.size(), m = txt.size();
    for (int i = n + 1; i < n + m + 1; i++)
    {
        if (pref[i] == n)
        {
            pos_of_occurences.push_back(i - 2 * n);
        }
    }
    // The occurences in txt
    for (auto x : pos_of_occurences)
    {
        cout << x << " ";
    }
    cout << endl;
}

signed main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// distinct subtrings in a string using hashing, 2 bases, 2 mods
//  probability of two random strings colliding is about 1/(p^2) where p is the base
//  so we can use two bases and two mods to avoid collision

auto distinct_substrings = [&](string const &a, vector<int> &pref, int k) -> int
{
    int n = a.size();
    vll p_pow1(n + 1, 1), p_pow2(n + 1, 1);

    for (int i = 1; i <= n; i++)
    {
        p_pow1[i] = (p_pow1[i - 1] * p1) % MOD1;
        p_pow2[i] = (p_pow2[i - 1] * p2) % MOD2;
    }

    vll h1(n + 1, 0), h2(n + 1, 0), rev_h1(n + 1, 0), rev_h2(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        h1[i + 1] = (h1[i] * p1 + a[i]) % MOD1;
        h2[i + 1] = (h2[i] * p2 + a[i]) % MOD2;
        // rev for palindrome checking
        // rev_h1[i + 1] = (rev_h1[i] * p1 + a[n - i - 1]) % MOD1;
        // rev_h2[i + 1] = (rev_h2[i] * p2 + a[n - i - 1]) % MOD2;
    }

    int cnt = 0;
    for (int l = 1; l <= n; l++)
    {
        set<ll> st;
        for (int i = 0; i + l <= n; i++)
        {
            ll a1 = (h1[i + l] - h1[i] * p_pow1[l] % MOD1 + MOD1) % MOD1;
            ll a2 = (h2[i + l] - h2[i] * p_pow2[l] % MOD2 + MOD2) % MOD2;
            ll h = a1 << 32 | a2; // gives a unique value
            st.insert(h);
        }
        cnt += st.size();
    }
    return cnt;
};
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// Rabin Karp Algorithm
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1, MOD = (int)(1e9 + 7);
#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define forl(i, a, b, k) for (ll i = a; i < b; i += k)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
const int p = 131;

inline void solve(int n)
{
    string a, b;
    cin >> a >> b;

    if (a.size() > b.size())
    {
        cout << " " << endl;
        return;
    }

    int n = b.size();
    vector<int> hsh(n + 1, 0);
    vector<int> pw(n + 1, 1);

    auto compute_hash = [&](string const &s) -> int
    {
        // computes hash of a string
        int hash_v = 0;
        for (char c : s)
        {
            hash_v = (hash_v * p + c) % MOD;
        }
        return hash_v;
    };

    int hash_val = compute_hash(a);
    for (int i = 1; i <= n; i++)
    {
        // computes hash of a string also stores for substrings
        hsh[i] = (hsh[i - 1] * p + (b[i - 1])) % MOD;
        pw[i] = pw[i - 1] * p % MOD;
    }

    auto hash_substring = [&](int l, int r) -> int
    {
        int h1 = (hsh[r + 1] - hsh[l] * pw[r - l + 1] % MOD + MOD) % MOD;
        return h1;
    };

    for (int l = 0, r = n - 1; r < n; l++, r++)
    {
        if (hash_val == hash_substring(l, r))
        {
            cout << l << endl;
        }
    }
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    while (cin >> n)
    {
        solve(n);
    }

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// z_function:
// The Z-array z of a string s of length n contains for each k = 0,1,...,n - 1 the
// length of the longest substring of s that begins at position k and is a prefix of string s. 
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
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

