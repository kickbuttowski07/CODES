// IMPLEMNTATION OF QUEUE USING ARRAY
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
#define ll long long
#define vll vector<ll>
#define forl(i, a, b, k) for (ll i = a; i < b; i += k)
#define Sort(a) sort(a.begin(), a.end());
#define MOD 1000000007
class Queue {
    int *queue;
    int start, end, currSize, maxSize;

public:
    Queue() {
        // Creation a array of queue
        queue = new int[16];
        start = -1;
        end = -1;
        currSize = 0;
    }
    Queue(int maxSize) {
        (*this).maxSize = maxSize;
        queue = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }
    void push(int val) {
        // value to be queued or pushed
        if (currSize == maxSize) {
            cout << "Queue is full" << endl;
            exit(1);
        }
        if (end == -1) {
            start = 0;
            end = 0;
        }
        else {
            end = (end + 1) % maxSize;
        }
        queue[end] = val;
        cout << "The element pushed is = " << val << endl;
        currSize++;
    }
    void pop() {
        if (start == -1) {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        int popped = queue[start]; // storing the element which is popping
        if (currSize == 1) {
            start = -1;
            end = -1;
        }
        else {
            start = (start + 1) % maxSize;
        }
        currSize--;
        cout << "poped element = " << popped << endl;
        exit(1);
    }
    int top() {
        if (start == -1) {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return queue[start];
    }
    int size() {
        return currSize;
    }
};
inline void solve()
{
    Queue q(6);
    q.push(4);
    q.push(6);
    q.push(1);
    cout << "top = " << q.top() << endl;
    q.push(3);
    q.push(5);
    q.push(2);
    q.push(7);
    q.pop();
    q.pop();
    q.push(10);
    cout << "size = " << q.size() << endl;
}
int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    //  freopen("output.txt", "w", stdout);
#endif
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




//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
