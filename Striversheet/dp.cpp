// try to implement what you are thinking instead of wasting time by thinking its not the way
// do in all possible ways to implement what you are thinking   


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
