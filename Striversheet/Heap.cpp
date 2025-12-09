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

void swap(int *x, int *y);

// A class for Min Heap
class MinHeap {
    int *harr;
    int capacity;
    int heap_size;
  public:

    MinHeap(int capacity);

    void MinHeapify(int i);

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return (2 * i + 1);
    }

    int right(int i) {
        return (2 * i + 2);
    }

    int extractMin(); // remove the minimum

    void decreaseKey(int i, int new_val); // change a value to new value at index = i

    int getMin() {
        return harr[0];
    }

    void deleteKey(int i); 

    void insertKey(int k);
};

MinHeap::MinHeap(int capacity) {
    this->heap_size = 0;
    this->capacity = capacity;
    harr = new int[capacity];
}

void MinHeap::insertKey(int k) {
    if (heap_size == capacity) {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // First insert the new key at the end
    int i = heap_size;
    harr[i] = k;
    heap_size++;

    // Fix the min heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// Decreases value of key at index 'i' to new_val.  
// It is assumed that new_val is smaller than harr[i].
void MinHeap::decreaseKey(int i, int new_val) {
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

// Method to remove minimum element (or root) from min heap
int MinHeap::extractMin() {
    // Remove the top and place the last element to top and heapify.
    if (heap_size <= 0) {
        return INT_MAX;
    }
    if (heap_size == 1) {
        heap_size--;
        return harr[0];
    }

    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);
    return root;
}

// This function deletes key at index i. It first reduced value to minus
// infinite, then calls extractMin()
void MinHeap::deleteKey(int i) {
    decreaseKey(i, INT_MIN); // so that this node become the minimum of the heap and extract the minimum.
    extractMin();
}

// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MinHeap::MinHeapify(int i) { // O(log(n)) or O(h)
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i]) {
        smallest = l;
    }
    if (r < heap_size && harr[r] < harr[smallest]) {
        smallest = r;
    }
    if (smallest != i) {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

// A utility function to swap two elements

class Heapsort {
    vector<int> arr;
    int n;

public:
    Heapsort(vector<int>a, int n) : n(n), arr(n, 0) {
        for (int i = 0; i < n;i++) {
            arr[i] = a[i];
        }
    }
    int left(int i) {
        return (2 * i + 1);
    }
    int right(int i) {
        return (2 * i + 2);
    }

    void heapify(vector<int>&arr, int n, int i) {
        int l = left(i), r = right(i);
        int smallest=i;
        if(l < n && arr[l] > arr[smallest]) {
            smallest = l;
        }
        if(r < n && arr[r] > arr[smallest]) {
            smallest = r;
        }
        if(smallest != i) {
            swap(&arr[smallest], &arr[i]);
            heapify(arr, n, smallest);
        }
    } // For one call it is O(log n)    

    void BuildMaxHeap(void) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        } // O(n)
        for (int i = n - 1; i >= 0; i--) {
            swap(&arr[0], &arr[i]);
            heapify(arr, n, i);
            // here itself we can sort the array inplace, by swaping the top with (size - 1) and heapify upt size - 1
        }
    }
};

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
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