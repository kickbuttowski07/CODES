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


template <class T = int> class Sort{
private:
    vector<int> SelSort;
    vector<int> InsSort;
    vector<int> BubSort;
    int n;
public:
    Sort(vector<int> &a, int n) : n(n) {
        SelSort = a;
        InsSort = a;
        BubSort = a;
    }

    void Selection() {
        // O(N), O(N^2), O(N^2) -> B,A,W
        // Requires only a constant O(1) extra memory space.
        // It requires less number of swaps (or memory writes) compared to many other standard algorithms.
        for (int i = 0; i < n;i++) {
            int curr = i;
            for (int j = i + 1; j < n;j++){
                if(SelSort[curr] > SelSort[j]) {
                    curr = j;
                }
            }
            swap(SelSort[i], SelSort[curr]);
        }
    }

    void printSelSort() {
        for (int i = 0; i < n;i++){
            cout << SelSort[i] << " ";
        }
        cout << endl;
    }

    void Insertion() {
        // O(N), O(N^2), O(N^2) -> B,A,W
        // number of inversions is directly proportional to number of swaps. 
        for (int i = 1; i < n;i++){
            int key = InsSort[i];
            int j = i - 1;
            while (j >= 0 && InsSort[j] > key) {
                InsSort[j + 1] = InsSort[j];
                j = j - 1;
            }
            InsSort[j + 1] = key;
        }
    }

    void printInsSort() {
        for (int i = 0; i < n;i++){
            cout << InsSort[i] << " ";
        }
        cout << endl;
    }

    void Bubble() {
        // O(N), O(N^2), O(N^2) -> B,A,W
        // It does not require any additional memory space.
        bool swapped;
        for (int i = 0; i < n - 1; i++) {
            swapped = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (BubSort[j] > BubSort[j + 1]) {
                    swap(BubSort[j], BubSort[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
    }

    void printBubSort() {
        for (int i = 0; i < n;i++){
            cout << BubSort[i] << " ";
        }
        cout << endl;
    }
};

template<class T = int>
class Mergesort {
private:
    vector<int> a;
    int n;

public:
    Mergesort(vector<int> curr, int n) : a(move(curr)), n(n) {}

    int merge(int l, int r, int m) {
        int cnt = 0;
        int left = m - l + 1, right = r - m;
        vector<int> back(left), front(right);

        for (int i = l; i <= m; i++) {
            back[i - l] = a[i];
        }
        for (int i = m + 1; i <= r; i++) {
            front[i - (m + 1)] = a[i];
        }

        int i = 0, j = 0, k = l;
        while (i < left && j < right) {
            // Correct rule: no inversion when back[i] <= front[j]
            if (back[i] <= front[j]) {
                a[k++] = back[i++];
            } else {
                a[k++] = front[j++];
                cnt += (left - i); // all remaining in back are > front[j-1]
            }
        }
        while (i < left) {
            a[k++] = back[i++];
        }
        while (j < right) {
            a[k++] = front[j++];
        }

        return cnt;
    }

    int merge_sort(int l, int r) {
        if (l >= r) return 0;
        int mid = l + (r - l) / 2;
        int ans = 0;
        ans += merge_sort(l, mid);
        ans += merge_sort(mid + 1, r);
        ans += merge(l, r, mid);
        return ans;
    }

    void sort(int l, int r) { 
        (void)merge_sort(l, r); 
    }

    void print() {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << '\n';
    }

    int inv_cnt() { 
        return merge_sort(0, n - 1); 
    }
};

inline void solve() {
    int n;
    cin >> n;
    vector<int> ans(n);
    for (int i = 0; i < n;i++){
        cin >> ans[i];
    }
    Sort<>obj(ans, n);
    obj.Selection();
    obj.printSelSort();
    obj.Insertion();
    obj.printInsSort();
    obj.Bubble();
    obj.printBubSort();
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