// Imp Notes:
// Use lcm as (a / __gcd(a, b)) * b instead of (a * b/ __gcd(a, b)) integer overflow may causes

// Number is of the form : x1^k1 * x2^k2 * .......
// No of Divisors: (k1 + 1)*(k2 + 1)*(k3 + 1).....
// sum of Divisors : ((x1^(k1 + 1) - 1) / (x1 - 1))*((x2^(k2 + 1) - 1) / (x2 - 1))*..........
// product of divisors : num ^ (d(num) / 2), d(num) -> no of divisors

// Clearly see the constraints, optimise code according to it

// Cses Mathematics:
// Counting Co prime Pairs
// Mobius Function to calc overlapping multiples of a prime factor by allocating -1(odd), 0(square), 1(even) contribution

// Extended Euclidean Algorithm -> finds integer solution of the equation: ax + by = gcd(a, b)
// Bezout Lemma says that if a, b are 2 integers, d is gcd(a, b) then exist x & y such that ax + by = d;

// If (x, y) pair satisfy the above equation then all pairs (x + ((k * b) / gcd(a, b)), y - ((k * a) / gcd(a, b)) for every integer k, satisfy the equation
// For n ≤ 10^12, max distinct primes ≤ 12 (in fact, ≤ 10, because product of first 12 primes > 10^12).


// Euler Totient function(ETF) counts no of +ve integers upto n which are co prime to n, Φ(n) = no of +ve integer co prime to n.




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

ll sub(ll a, ll b, ll m) {
    return ((a % m) - (b % m) + m) % m;
}

ll power(ll x, ll y) {
    ll power = x, sum = 1;
    if (x == 0) {
        sum = 0;
    }
    while (y > 0) {
        if ((y & 1) == 1) {
            sum *= power;
        }
        power *= power;
        y = y >> 1;
    }
    return sum;
}

ll fast_pow(ll a, ll p, ll m) {
    ll res = 1;
    while (p) {
        if (p % 2 == 0) {
            a = (a * a) % m;
            p /= 2;
        } else {
            res = (res * a) % m;
            p--;
        }
    }
    return res % m;
}

ll modInverse(ll a, ll m) {
    return fast_pow(a, m - 2, m);
}

ll divide(ll a, ll b, ll m) {
    return mul(a, modInverse(b, m), m);
}
                                    
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
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


class Euler_totient {
public:
    int phi1(int n) {
        // Time complexity O(sqrt(n))
        // Upto 1e12
        // Using the Prime Factorisation
        // Read CP - Algorithms about Euler totient Function
        // Φ(n) = n * ((p1 - 1) / p1) * ((p2 - 1) / p2) * ..........
        int num = n;
        for (int i = 2; i * i <= n;i++) {
            if(n % i) {
                continue;
            }
            num /= i;
            num *= (i - 1);
            while(n % i == 0) {
                n /= i;
            }
        }
        if(n > 1) {
            num /= n;
            num *= (n - 1);
        }
        return num;
    }

    vector<int> phi2(int n) {
        // no of co primes for each number using sieve
        // Gives phi(i) up to 0 <= i <= n;
        // Time complexity O(nloglogn)
        vector<int> phi(n + 1);

        // Initialize phi(i) = i for all i >= 1
        for (int i = 0; i <= n; i++) {
            phi[i] = i; // Φ(p) = p - 1, if p is prime
        }
        
        for (int i = 2; i <= n; i++) {
            if (phi[i] == i) { // i is prime
                for (int j = i; j <= n; j += i) {
                    phi[j] -= phi[j] / i;
                }
            }
        }
        return phi;
    }
    // above is better
    vector<int> phi3(int n) {
        // Gives phi(i) up to 0 <= i <= n;
        // Using Divisor Sum Property
        // Time complexity O(nlogn)
        vector<int> phif(n + 1);
        phif[0] = 0;
        phif[1] = 1;
        for (int i = 2; i <= n; i++) {
            phif[i] = i - 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 2 * i; j <= n; j += i) {
                phif[j] -= phif[i];
            }
        }
        return phif;
    }
};
// Prime Factorisation
function<vector<pair<int, int>>(int)> primeFactors = [&](int n) -> vector<pair<int, int>> {
    map<int, int> mp;
    while (n % 2 == 0) {
        mp[2]++;
        n = n / 2;
    }
    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            mp[i]++;
            n = n / i;
        }
    }
    if (n > 2) {
        mp[n]++;
    }

    vector<pair<int, int>> vp;
    for(auto it : mp) {
        vp.push_back({it.F, it.S});
    }

    return vp;
};

// prime or SieveOfEratosthenes
// we can do upto 9e8 in 1.5sec
// However, for the simple implementations of the Sieve of Eratosthenes using a vector<bool> is faster. 
// You are limited by how fast you can load the data into the cache, and therefore using less memory gives a big advantage. 
// A benchmark (link) shows, that using a vector<bool> is between 1.4x and 1.7x faster than using a vector<char>.

vector<char> prime(N + 1, true);
vector<int> v;
function<void(void)> Sieve = [&](void) -> void {
    prime[0] = false, prime[1] = false;
    for (int p = 2; p * p <= N; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= N; i += p) {
                prime[i] = false;
            }
        }
    } // Nloglog(sqrt(N)); in general NloglogN which 2nd loop starts from p but here it starts from p * p
    for (int i = 1; i <= N; i++) {
        if (prime[i]) {
            v.push_back(i);
        }
    }
};

function<bool(int)> isprime = [&](int n) -> bool {
    // O(sqrt(n)) 
    for (int i = 2; i * i <= n;i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return (n >= 2);
};


// Segmented Sieve L, R <= 1e12 but R - L + 1 <= 1e7
function<vector<char>(int, int)> SegSieve = [&](int L, int R) -> vector<char>{
    // Time Complexity = O((R - L + 1)loglog(R) + sqrt(R)loglog(sqrt(r)))

    int lim = sqrt(R);
    vector<char> mark(lim + 1, false);
    vector<int> primes;
    for (int i = 2; i <= lim; ++i) {
        if (!mark[i]) {
            primes.emplace_back(i);
            for (int j = i * i; j <= lim; j += i) {
                mark[j] = true;
            }
        }
    } // -> sqrt(R)loglog(sqrt(r))
    
    vector<char> isPrime(R - L + 1, true);
    for (int i : primes) {
        for (int j = max(i * i, (L + i - 1) / i * i); j <= R; j += i) {   // [max(i * i, (L + i - 1) / (i * i), R)]
            isPrime[j - L] = false;
        }
    } // -> O((R - L + 1)loglog(R)
    if (L == 1) {
        isPrime[0] = false;
    }
    return isPrime; // do l + i to get the number while traversing
};


// Odd Sieve

function<vector<int>(int)> OddSieve = [&](int n) -> vector<int> {
    int M = (n >> 1); // only odds
    vector<char> is_prime(M + 1, true);
    vector<int> res;
    res.reserve(6000000);

    res.push_back(2); // 2 is prime

    int limit = sqrt(n);
    for (int i = 1; (2 * i + 1) <= limit; i++) {
        if (is_prime[i]) {
            int p = 2 * i + 1;
            for (long long j = 1LL* p * p; j <= n; j += 2 * p) {
                is_prime[j >> 1] = false;
            }
        }
    }
    for (int i = 1; 2 * i + 1 <= n; i++) {
        if (is_prime[i]) res.push_back(2 * i + 1);
    }
    return res;
};


// Factors
function<vector<int>(int)> factors = [&](int n) -> vector<int> {
    vector<int> fac;
    for (int i = 1; i * i <= n;i++) {
        if (n % i == 0) {
            fac.push_back(i);
            if(i * i != n) {
                fac.push_back(n / i);
            }
        }
    }
    return fac;
};
// Smallest Prime Factor
// spf O(nloglogn)
// upto 1e6
vector<int> fac[N];
vector<int> spf(N, 1);
bool prime[N + 1];
// fill(prime, prime + N + 1, true);
function<void(void)> Sieve = [&](void) -> void {
    prime[0] = false, prime[1] = false;
    for (int p = 2; p < N; p++) {
        if (prime[p] == true) {
            spf[p] = p;
            for (int i = p * p; i < N; i += p) {
                prime[i] = false;
                spf[i] = p;
            }
        }
    }
    for (int i = 2; i < N; i++) {
        if (spf[i] == 0) spf[i] = i;
    }

    for (int i = 2; i < N; i++) {
        for (int j = i; j < N; j += i) {
            fac[j].pb(i);
        }
    }
};

// Counting divisors in ((n + x)logx)
vector<int> v(N);
void div_init(int n) {
    for (int i = 2; i <= n; i++) {
        if (v[i] == 0) {
            for (int j = i; j <= n; j += i) {
                v[j] = i;
            }
        }
    }
}
// Euclidean Algorithm O(log(min(a, b)))
function<int(int, int)> gcd = [&](int a, int b) -> int {
    if(b == 0) {
        return a;
    }
    return gcd(b, a % b);
};

// ax + by = gcd(a, b) -> solutions
// Extended Euclidean Algorithm O(log(min(a, b)))
function<int(int, int, int&, int&)> EE_gcd = [&](int a, int b, int &x, int &y) -> int {
    if (b == 0) {
        x = (a >= 0 ? 1 : -1); // Handle sign
        y = 0;
        return llabs(a);
    }
    int x1, y1;
    int d = EE_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return d;
};


// No of Coprime Pairs in array O(n + mlogm) m->max elem in array, n = size of array

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1, MOD = (int)(1e9 + 7);
#define int long long
#define ll long long
#define forl(i, a, b, k) for (ll i = a; i < b; i += k)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define pb push_back
                                    
                                    
#define F first
#define S second

inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    vector<int> mp(N + 1, 0);
    for (int i = 0; i < n;i++){
        cin >> a[i];
        mp[a[i]]++;
        mx = max(mx, a[i]);
    }

    vector<bool> prime(mx + 1, true);
    vector<int> mu(mx + 1, 1);
    function<void(int)> Mobius = [&](int mxx) -> void {
        // Odd distinct primes -> -1
        // Even distinct primes -> 1
        prime[0] = false, prime[1] = false;
        mu[0] = 0, mu[1] = 1;
        for (int p = 2; p <= mxx; p++) {
            if (prime[p]) {
                for (int i = p; i <= mxx; i += p) {
                    prime[i] = false;
                    mu[i] *= -1;
                }
                // square free -> 0
                for (int i = p * p; i <= mxx; i += p * p) {
                    mu[i] = 0;
                }
            }
        }
    };
    Mobius(mx);

    vector<int>cnt(mx + 1, 0);
    for (int i = 1; i <= mx; i++){
        for (int j = i; j <= mx; j += i){
            cnt[i] += mp[j];
        }
    }
    int ans = 0;
    for (int i = 1; i <= mx;i++) {
        if(mu[i] == 0 || cnt[i] < 2) {
            continue;
        }
        ans += mu[i] * ((cnt[i] * (cnt[i] - 1)) / 2);
    }
    cout << ans << endl;
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


// Fermat's Little Theorem:
//       If p is a prime number and p doesn't divide A then Apow(p-1) congruent to 1 mod (p);
//       Ex: 2pow(5-1) congruent to 1 mod (5);
//           3pow(5-1) congruent to 1 mod (5);
//           4pow(5-1) congruent to 1 mod (5);
//           6pow(5-1) congruent to 1 mod (5);


// k*k sub arrays in n*m 2d array
// for (ll i = 0; i < n; i++) {
//     for (ll j = 0; j < m; j++) {
        
//         ll r_s = max(0ll, i - k + 1);
//         ll r_e = min(i, n - k);
//         ll r_c = max(0ll, r_e - r_s + 1);

//         ll c_s = max(0ll, j - k + 1);
//         ll c_e = min(j, m - k);
//         ll c_c = max(0ll, c_e - c_s + 1);
//         arr[i][j] = r_c * c_c;
//     }
// }