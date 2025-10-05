// https://leetcode.com/problems/reverse-pairs/description/?envType=problem-list-v2&envId=binary-indexed-tree
// https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/?envType=problem-list-v2&envId=binary-indexed-tree
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
// ------------------------------------------------------------------------------------------------------------------------------------------------------
// 28-01-2025
// Binary Indexed Tree(BIT) (or) Fenwick Tree: 
// Used for Range dynamic queries, use one indexed structure
// Static queries we can do: N <= 1e7, take upto k = 25
// Sum: O(n) Prefix sum
//      for each query in O(1), preprocessing takes O(n) ;
// Min or Max: O(nlogn) Using sparse table dp[n][1 << n];
//             for each query can do in logn tc, Preprocessing takes O(nlogn);
// Xor : same as Sum

// SPARSE TABLE METHOD
// POINT UPDATE RANGE QUERY
#include <bits/stdc++.h>
using namespace std;
 
const int N = 2e5 + 1, mod = (int)(1e9 + 7);
#define ll long long
#define vll vector<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define forl(i, a, b, k) for (ll i = a; i < b; i += k)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define pb push_back

template <class T>
class BIT {
private:
    int size;
    vector<T> bit;
    // 0-based
public:
    BIT(int size) : size(size), bit(size + 1) {}

    void add(int idx, T val) {
        ++idx;  // shift to 1-based internally
        while (idx <= size) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    T pref_sum(int idx) {
        ++idx;  // shift to 1-based
        T total = 0;
        while (idx > 0) {
            total += bit[idx];
            idx -= idx & -idx;
        }
        return total;
    }

    T query_sum(int l, int r) {
        return pref_sum(r) - (l > 0 ? pref_sum(l - 1) : 0);
    }
};



void batman()
{

}
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int _ = 1;
    // cin >> _;
    while (_--)
    {
        batman();
    }
}


//CO ORDINATE COMPRESSION
// vector<ll> all;
// push_back everying u want to compress
// for (int i = 0; i < n; i++) {
//     all.push_back(a[i]);
//     all.push_back((ll)a[i] * 2);
// }
// sort(all.begin(), all.end());
// all.erase(unique(all.begin(), all.end()), all.end());

// auto get = [&](ll x) {
//     return lower_bound(all.begin(), all.end(), x) - all.begin() + 1;
// };
// use get to get the index of the value in the compressed array
// the bit size as the size of all + 2;
// also choose which direction u want to traverse

// 2DBIT ONE INDEXING
template <class T> class BIT2D {
  private:
    int rows, cols;
    vector<vector<T>> bit, arr;

  public:
    BIT2D(int rows, int cols) : rows(rows), cols(cols), bit(rows + 1, vector<T>(cols + 1, 0)), arr(rows + 1, vector<T>(cols + 1, 0)) {}

    /** Sets the value at (x, y) to val. */
    void set(int x, int y, T val) { add(x, y, val - arr[x][y]); }

    /** Adds val to the element at (x, y). */
    void add(int x, int y, T val) {
        arr[x][y] += val;
        for (int i = x; i <= rows; i += i & -i) {
            for (int j = y; j <= cols; j += j & -j) {
                bit[i][j] += val;
            }
        }
    }

    // Gives sum in the rectangular range [(1,1), (x,y)]
    T pref_sum(int x, int y) {
        T total = 0;
        for (int i = x; i > 0; i -= i & -i) {
            for (int j = y; j > 0; j -= j & -j) {
                total += bit[i][j];
            }
        }
        return total;
    }

    // Gives sum in the range [(x1,y1), (x2,y2)]
    T query_sum(int x1, int y1, int x2, int y2) {
        return pref_sum(x2, y2) - pref_sum(x1 - 1, y2) -
               pref_sum(x2, y1 - 1) + pref_sum(x1 - 1, y1 - 1);
    }

    void print() {
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                cout << bit[i][j] << " ";
            }
            cout << endl;
        }
    }
};



// RANGE UPDATE POINT / RANGE QUERY and RANGE QUERY
// will use 2 BITs
template <class T> class BIT {
  private:
    int size;
    vector<T> bit1, bit2;
    
    /** Internal function to add value to BIT */
    void internal_add(vector<T> &bit, int idx, T val) {
        while (idx <= size) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }
    
    /** Internal function to compute prefix sum */
    T internal_sum(vector<T> &bit, int idx) {
        T total = 0;
        while (idx > 0) {
            total += bit[idx];
            idx -= idx & -idx;
        }
        return total;
    }

  public:
    BIT(int size) : size(size), bit1(size + 1, 0), bit2(size + 1, 0) {}

    /** Adds val to the range [l, r] */
    void add_range(int l, int r, T val) {
        internal_add(bit1, l, val);
        internal_add(bit1, r + 1, -val);
        internal_add(bit2, l, val * (l - 1));
        internal_add(bit2, r + 1, -val * r);
    }

    /** Computes prefix sum in range [1, idx] */
    T pref_sum(int idx) {
        return internal_sum(bit1, idx) * idx - internal_sum(bit2, idx);
    }

    /** Computes sum in range [l, r] */
    T query_sum(int l, int r) {
        return pref_sum(r) - pref_sum(l - 1);
    }
};
