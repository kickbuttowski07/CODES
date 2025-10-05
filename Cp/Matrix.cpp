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
                       
ll mul(ll a, ll b, ll m) {
    return ((a % m) * (b % m)) % m;
}

ll add(ll a, ll b, ll m) {
    return ((a % m) + (b % m)) % m;
}
//  | 1   1 | ^ (n-1)  --->   | f(n)   f(n-1) |
//  | 1   0 |                 | f(n-1) f(n-2) |



//  | a+b  b |
//  | b    a |

class mat2d{
private:
    vector<vector<int>> mat;
    int Mod = (int)(1e9 + 7);
public:
    mat2d(int a, int b) {
        mat = vector<vector<int>>(2, vector<int>(2));
        mat[0][0] = mat[0][1] = mat[1][0] = b % Mod;
        mat[1][1] = a % Mod;
    }

    void multiply(vector<vector<int>>& m1, const vector<vector<int>>& m2){
        int w = add(mul(m1[0][0], m2[0][0], Mod), mul(m1[0][1], m2[1][0], Mod), Mod);
        int x = add(mul(m1[0][0], m2[0][1], Mod), mul(m1[0][1], m2[1][1], Mod), Mod);
        int y = add(mul(m1[1][0], m2[0][0], Mod), mul(m1[1][1], m2[1][0], Mod), Mod);
        int z = add(mul(m1[1][0], m2[0][1], Mod), mul(m1[1][1], m2[1][1], Mod), Mod);
        m1[0][0] = w % Mod; m1[0][1] = x % Mod; m1[1][0] = y % Mod; m1[1][1] = z % Mod;
    }

    vector<vector<int>> fib(vector<vector<int>> m, int p) {
        vector<vector<int>> res = {{1, 0}, {0, 1}};
        while (p > 0) {
            if (p & 1) {
                multiply(res, m);
            }
            multiply(m, m);
            p >>= 1;    
        }
        return res;
    }

    int pw(int p, int a, int b) {
        if (p == 0) return 0;
        mat2d base(a, b);
        auto P = fib(mat, p - 1);
        return (mul(P[0][0], b, Mod) + mul(P[0][1], a, Mod)) % Mod;
    }
};

inline void solve() {
    int p;
    cin >> p;
    mat2d m(0, 1);
    cout << m.pw(p, 0, 1) << endl;
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
    

// Matrix Transformations:
using vec10 = array<int, 10>;
using matrix = array<vec10, 10>; // 10x10 transformation matrix

static matrix identityMatrix() {
    matrix I{};
    for (int i = 0; i < 10; i++) I[i][i] = 1;
    return I;
}

static matrix operator*(const matrix& A, const matrix& B) {
    matrix C{};
    for (int i = 0; i < 10; i++) {
        for (int k = 0; k < 10; k++) if (A[i][k]) {
            for (int j = 0; j < 10; j++) {
                C[i][j] = (C[i][j] + 1LL * A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    return C;
}

static vec10 operator*(const matrix& A, const vec10& X) {
    vec10 ans{};
    for (int i = 0; i < 10; i++) {
        int sum = 0;
        for (int j = 0; j < 10; j++) sum += 1LL * A[i][j] * X[j];
        ans[i] = sum % MOD;
    }
    return ans;
}

// Build transformation matrix (digit expansion rules)
static matrix build_M() {
    matrix M{};
    for (int i = 0; i < 10; i++) {
        if (i < 9) {
            M[i + 1][i] = 1;
        } else {
            M[0][i] = M[1][i] = 1;
        }
    }
    return M;
}

static matrix Mpow[61];

void precompute() {
    Mpow[0] = build_M();
    for (int i = 1; i <= 60; i++) {
        Mpow[i] = Mpow[i - 1] * Mpow[i - 1];
    }
}

vec10 applyPow(const vec10& f, int m) {
    vec10 res = f;
    for (int k = 0; m; k++, m >>= 1) {
        if (m & 1) res = Mpow[k] * res;
    }
    return res;
}