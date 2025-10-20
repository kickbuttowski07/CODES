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

inline void solve()
{
    
}

int main()
{
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
struct PairHash {
    size_t operator()(const std::pair<int, int>& p) const noexcept {
        // combine hashes of first and second
        return std::hash<long long>()(((long long)p.first << 32) ^
                                      (long long)(p.second));
    }
};
unordered_map<pair<int, int>, int, PairHash> mp;
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// check the use of lower bound and upper_bound in all the possible ways you can
// your thinking is correct if can do some hardwork at that point of time you can achieve the acceptance of the solution


// Lawda : if u want distinct values then dont use set use vector(sort, unique (mummyyyyyyy, wtf))

// emplace_back(x) -> is a built-in method used to insert an element at the end of the vector by constructing it in-place. 
// It means that the element is created directly in the memory allocated to the vector avoiding unnecessary copies or moves.

// __builtin_clz(x): the number of zeros at the beginning of the number
// __builtin_ctz(x): the number of zeros at the end of the number
// __builtin_popcountll(x): the number of ones in the long long number
// __builtin_parity(x): the parity (even or odd) of the number of ones
// __builtin_ffs(int) finds the index of the first (LSB) set bit

// has_single_bit: checks if the number is a power of two
// bit_ceil / bit_floor: round up/down to the next power of two
// rotl / rotr: rotate the bits in the number
// countl_zero / countr_zero / countl_one / countr_one: count the leading/trailing zeros/ones
// popcount: count the number of set bits

// you can get the number from the binary string by using the stoi function
// pair sort by sec in descending

// Moves"
vector<pair<int,int>> knight_moves = {
    {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
};

vector<int> dir = {0, 1, 0, -1, 0};

vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> dy = {-1,  0,  1,-1, 1,-1, 0, 1};


bool sortDescSecond(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return a.second > b.second;
}

// pair sort by sec in ascending
bool sortascSecond(const pair<ll, ll> &a, const pair<ll, ll> &b) {
    return a.second < b.second;
}
// is a number is power of other number
auto isPowerOfK = [&](ll n, ll k) -> bool {
    // Handle edge cases
    if (n == 1) {
        return true; // Any number is a power of 1
    }
    if (n == 0 || k == 0) {
        return false; // 0 cannot be expressed as a power of any number, and 0 ^ x = 0 but x != 0
    }

    ll power = 1;
    while (power < n) {
        if (power > __LONG_LONG_MAX__ / k) {// Overflow check
            return false;
        }

        power *= k;
        if (power == n) {// Found the power
            return true;
        }
    }
    return false;
};
// log_a to the base b
ll loga_baseb(ll a, ll b)
{
    return log2(a) / log2(b);
}
// number to binary
std::string decimalToBinary(ll decimalNumber)
{
    return bitset<2 * sizeof(decimalNumber)>(decimalNumber).to_string();
}
// second elements
struct myComp {
    constexpr bool operator()(
        pair<int, int> const &a,
        pair<int, int> const &b)
        const noexcept
    {
        return a.second < b.second;
    }
};
// Structure of the operator
// overloading for comparison
struct myComp
{
    constexpr bool operator()(
        pair<int, int> const &a,
        pair<int, int> const &b)
        const noexcept
    {
        return a.second > b.second;
    }
};
// decimal to binary string
auto dectobin = [&](ll n) -> string
{
    // adjust the length of the string
    string s = (bitset<8 * sizeof(n)>(n).to_string());
    reverse(s.begin(), s.end());
    return s;
};
// bitset must learn as it has set,reset,flip,count
// if u use cout << boolalpha << (k==n) << nl;it returns true or false

// series of i*(i+1) gives the repitation of remainders
// subset xor sum can be get by or of all values*pow(2,n-1);

///------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

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

inline void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // stores all possible subset sums in the interval [l, r]
    auto get_subset_sums = [&](int l, int r) -> vector<ll>
    {
        int len = r - l + 1;
        vector<ll> res;

        // loop through all subsets
        for (int i = 0; i < (1 << len); i++)
        {
            ll sum = 0;
            for (int j = 0; j < len; j++)
            {
                if (i & (1 << j))
                {
                    sum = (sum % x + a[l + j] % x) % x;
                }
            }
            res.push_back(sum);
        }

        return res;
    };

    vector<ll> left = get_subset_sums(0, n / 2 - 1);
    vector<ll> right = get_subset_sums(n / 2, n - 1);
}

int main()
{
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
// har har mahadev

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// Use lcm as (a / __gcd(a, b)) * b instead of (a * b/ __gcd(a, b)) integer overflow may causes
// when in DP dealing with and, or bit operations be care ful with all accumulated states
// https://codeforces.com/contest/1395/my
// be careful while writing base conditions in recursion in dp, write all possible base conditions

// Dynamic Programming
// 1. Edit distance:Leet Code Also In CSO 211 PROJECT We implemented it
// https://leetcode.com/problems/edit-distance/?envType=problem-list-v2&envId=dynamic-programming
// CSES Removal Game, Edit Distance
// https://codeforces.com/blog/entry/55274

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// ***********
// Minimum no of jumps needed to reach end, similarly we can do minimum no of intervals to cover target interval
// By making intervals (i, i + mx[i] - 1) at each i
// ll cnt = 0, curr_r = 0, max_r = 0;
// for (ll i = 0; i < n; i++) {
//     max_r = max(max_r, i + mx[i]);
//     if (i == curr_r) {
//         cnt++;
//         curr_r = max_r;
//         if (curr_r >= n) {
//             break;
//         }
//     }
// }
// // if we can't form the target
// if (curr_r < n) {
//     return -1;
// }
// return cnt;

// Sorting a pair according to the conditions, a[i] < a[j], b[i], b[j] (a, b) are pairs
// LIS -> sort a ->asc, b-> desc(to avoid conflicts with same a);