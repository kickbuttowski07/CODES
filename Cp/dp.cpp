// try to implement what you are thinking instead of wasting time by thinking its not the way
// do in all possible ways to implement what you are thinking  

// SORT and SKIP for distinct permutations or combinations  


// https://codeforces.com/contest/448/problem/C
// https://codeforces.com/contest/1316/my
// above is good (dp + bit) masking


// Matrix exponentiation
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1, MOD = (int)(1e9 + 7);
#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define forl(i, a, b, k) for (ll i = a; i < b; i += k)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define pb push_back
#define debug(x) cerr << #x << " = " << (x) << endl
                                


inline void solve()
{
    
}
                        
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
             
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
                
    return 0;
}

// LCS longest common subsequence to get the the string use the tabulation method and do
// ll n = s.size(), m = t.size();
// vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0));
// for (ll i = 1; i <= n; i++)
// {
//     for (ll j = 1; j <= m; j++)
//     {
//         if (s[i - 1] == t[j - 1])
//             dp[i][j] = dp[i - 1][j - 1] + 1;
//         else
//             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//     }
// }
// string ans = "";
// ll i = n, j = m;
// while (i > 0 && j > 0)
// {
//     if (s[i - 1] == t[j - 1])
//     {
//         ans += s[i - 1];
//         i--;
//         j--;
//     }
//     else if (dp[i - 1][j] > dp[i][j - 1])
//         i--;
//     else
//         j--;
// }

// reverse(ans.begin(), ans.end());
// cout << ans << endl;

// for subsequences sort the array if it is necessary for the problems


// Matrix chain multiplication information all

// digit dp sum of all digits of numbers in the range [a, b]
// in some cases product also consider but can't able to store them so we use unordered_map<string, int> dp
// https://leetcode.com/problems/numbers-with-repeated-digits/description/
// https://leetcode.com/problems/count-the-number-of-powerful-integers/description/

// always use the new updated values (nst, nt, nrem, nsum,......)

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1, MOD = (int)(1e9 + 7);
#define int long long
#define ll long long
#define forl(i, a, b, k) for (ll i = a; i < b; i += k)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define pb push_back
                                    
                                    
#define F first
#define S second

int a, b;


int ddp(string s) {
    int len = s.size();
    int dp[len + 1][2][2][len * 9 + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < 2;i++){
        for (int j = 0; j < 2;j++){
            for (int k = 0; k < len * 9 + 1;k++){
                dp[len][i][j][k] = k;
            }
        }
    }

    for (int idx = len - 1; idx >= 0;idx--){
        for (int t = 0; t < 2;t++){
            for (int st = 0; st < 2;st++){
                for (int sum = len * 9 - 1; sum >= 0; sum--) {
                    int ub = t ? (s[idx] - '0') : 9;
                    int ans = 0;
                    for (int d = 0; d <= ub;d++){
                        int nst = st || (d != 0); // mandatory in any case
                        ans += dp[idx + 1][t & (ub == d)][nst][sum + d];
                    }
                    dp[idx][t][st][sum] = ans;
                }
            }
        }
    }
    return dp[0][1][0][0];
}

inline void solve() {
    cin >> a >> b;
    if(a > 0){
        a--;
    }
    string l = to_string(a), r = to_string(b);
    cout << ddp(r) - ddp(l) << endl;
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

// Palindrome in Ranges
// for (int i = 0; i < n; i++) {
//     int l = i, r = i;
//     while (l >= 0 && r < n && s[l] == s[r]) {
//         dp[l][r] = 1;
//         l--, r++;
//     }
//     if (i + 1 < n) {
//         l = i, r = i + 1;
//         while (l >= 0 && r < n && s[l] == s[r]) {
//             dp[l][r] = 1;
//             l--, r++;
//         }
//     }
// }

// for (int len = 1; len <= n; len++) {
//     for (int l = 0; l + len - 1 < n; l++) {
//         int r = l + len - 1;
//         if (l == r) {
//             dp[l][r] = 1;
//         }
//         else {
//             dp[l][r] = (l + 1 <= r ? dp[l + 1][r] : 0) + (l <= r - 1 ? dp[l][r - 1] : 0) - (l + 1 <= r - 1 ? dp[l + 1][r - 1] : 0) + (dp[l][r] ? 1 : 0);
//         }
//     }
// }

// Buckets method lower bound:
// for (int i = 0; i < n; i++) {
//     auto it = lower_bound(temp.begin(), temp.end(), a[i]);
//     int idx = it - temp.begin();
//     if (it == temp.end()) {
//         temp.push_back(a[i]);
//     } else {
//         *it = a[i];
//     }
//     LIS[i] = idx + 1;
// }

// lower bound strictly increasing, upper bound non decreasing.


