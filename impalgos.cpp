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
                                    
// Nqueen Problem O(n!n) solution
inline void solve() {
    int n;
    cin >> n;
    function<bool(int row, int col, vector<vector<int>> &mat)> is_safe = [&](int row, int col, vector<vector<int>> &mat) -> bool{
        int n = mat.size();
        int i, j;

        // return 0, if already a queen present in that column, diagonal;

        // check this column on upper side
        for (i = 0; i < row; i++){
            if (mat[i][col]){
                return 0; 
            }
        }
        // Check upper diagonal on left side
        for (i = row-1, j = col-1; i >= 0 && 
            j >= 0; i--, j--)
            if (mat[i][j])
                return 0;

        // Check lower diagonal on left side
        for (i = row-1, j = col+1; j < n && 
            i >= 0; i--, j++) {
            if (mat[i][j]) {
                return 0;
            }
        }
        return 1;
    };
    function<int(int, vector<vector<int>>&)>place_queen=[&](int row, vector<vector<int>>& mat) -> int {
        if(row == n){
            return 1;
        }
        for (int col = 0; col < n;col++){
            if(is_safe(row, col, mat)){
                mat[row][col] = 1; // Place the queen
                if(place_queen(row + 1, mat)){
                    return 1; // If placing the next queen is successful
                }
                mat[row][col] = 0; // Backtrack
            }
        }
        return 0;
    };
    function<vector<int>(int)> n_queen = [&](int n) -> vector<int>{
        vector<vector<int>> mat(n, vector<int>(n, 0));
        vector<int> ans;
        if(place_queen(0, mat)){
            for (int col = 0; col < n;col++){
                for (int row = 0; row < n;row++){
                    if(mat[row][col]==1){
                        ans.push_back(row + 1);
                    }
                }
            }
        }
        else{
            ans = {-1};
        }
        return ans;
    };
    vector<int> ans = n_queen(n);
    for (int i = 0; i < n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
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
        if(t) {
            cout << endl;
        }
    }
                
    return 0;
}
// JAI SHREE RAM

// Merge Sort

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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    function<void(int, int, int)> merge = [&](int l, int r, int m) -> void {
        int n1 = m - l + 1, n2 = r - m;
        vector<int> left(n1), right(n2);
        for (int i = l; i <= m;i++){
            left[i - l] = a[i];
        }
        for (int i = m + 1; i <= r;i++){
            right[i - m - 1] = a[i];
        }
        int i = 0, j = 0, k = l;
        while(i < n1 && j < n2) {
            if(left[i] <= right[j]) {
                a[k++] = left[i++];
            } else {
                a[k++] = right[j++];
            }
        }
        while(i < n1) {
            a[k++] = left[i++];
        }
        while(j < n2) {
            a[k++] = right[j++];
        }
    };

    function<void(int, int)> merge_sort = [&](int l, int r) -> void {
        if(l >= r) {
            return;
        }
        int mid = l + (r - l) / 2;
        // Sort and then merge
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
        merge(l, r, mid);
    };

    merge_sort(0, n - 1);
    for (int i = 0; i < n;i++){
        cout << a[i] << " ";
    }
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
        if(t) {
            cout << endl;
        }
    }
                
    return 0;
}
// JAI SHREE RAM

// Binary search square roor
// int n, k;
// cin >> n >> k;
// float ans = 0.0;
// int l = 0, r = n;
// while(l <= r){
//     int mid = l + (r - l) / 2;
//     if(mid * mid == n){
//         ans = mid;
//         break;
//     }
//     else if(mid * mid < n){
//         ans = mid;
//         l = mid + 1;
//     }
//     else{
//         r = mid - 1;
//     }
// }
// double inc = 0.1;
// for (int i = 0; i < k;i++){
//     while(ans * ans <= n){
//         ans += inc;
//     }
//     ans -= inc;
//     inc /= 10;
// }
// cout << ans;

