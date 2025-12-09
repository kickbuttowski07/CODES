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
                    
// Implementation of Queue using Array
class myQueue {
    // Array to store queue elements.
    int *arr;

    // Maximum number of elements the queue can hold.
    int capacity;

    // Current number of elements in the queue.
    int size;

  public:
    myQueue(int c) {
        this->capacity = c;
        this->arr = new int[capacity];
        this->size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == capacity;
    }

    // Adds an element x at the rear of the queue.
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        arr[size] = x;
        size++;
    }

    // Removes the front element of the queue.
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        for (int i = 1; i < size; i++) {
            arr[i - 1] = arr[i];
        }
        size--;
    }

    // Returns the front element of the queue.
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return arr[0];
    }
    // Return the last element of queue
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[size - 1];
    }
};

// Implementation of Circular Queue using array
class myQueue {
private:
     // fixed-size array
    int* arr;  
     // index of front element
    int front; 
     // current number of elements
    int size;   
      // maximum capacity
    int capacity;

public:
    myQueue(int cap) {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        size = 0;
    }

    // Insert an element at the rear
    void enqueue(int x) {
        if (size == capacity) {
            cout << "Queue is full!" << endl;
            return;
        }
        int rear = (front + size) % capacity;
        arr[rear] = x;
        size++;
    }

    // Remove an element from the front
    int dequeue() {
        if (size == 0) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        int res = arr[front];
        front = (front + 1) % capacity;
        size--;
        return res;
    }

    // Get the front element
    int getFront() {
        if (size == 0) return -1;
        return arr[front];
    }

    // Get the rear element
    int getRear() {
        if (size == 0) return -1;
        int rear = (front + size - 1) % capacity;
        return arr[rear];
    }
};
                                    
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