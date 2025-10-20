// Using Array (Fixedsize)
class Mystack{
    int top;
    int MAX;
    int *stk; // array

    public:
    Mystack(int MAX) {
        this->MAX = MAX;
        this->top = -1;
        this->stk = new int[this -> MAX];
    }

    void push(int val) {
        if(this -> top == MAX) {
            cout << "Stack Over flow" << endl;
        }
        else{
            this->stk[++top] = val;
        }
    }

    int pop(void) {
        if(this -> top == -1) {
            cout << "Stack Under flow" << endl;
            return -1;
        }
        else{
            return this->stk[top--];
        }
    }

    int size(void) {
        return this->top + 1;
    }

    bool isEmpty(void) {
        return this->top == -1;
    }

    bool isFull(void) {
        return this->top == this->MAX - 1;
    }

    int peek(void) {
        if(this -> top == -1) {
            return -1;
        }
        else{
            return this->stk[top];
        }
    }
};

// Using Linked List    (Dynamic)
class Node{
    public:
        int data;
        Node *next;
        Node(int val) {
            this->data = val;
            this->next = nullptr;
        }
};

class LLstack {
    Node *top;

public:
    LLstack(void) {
        this->top = nullptr;
    }

    void push(int val) {
        Node *temp = new Node(val);
        temp->next = top;
        top = temp;
    }

    int pop(void) {
        if(top == nullptr) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        Node *temp = top;
        int val = temp->data;
        top = top->next;
        delete temp;
        return val;
    }

    int peek(void) {
        if(top == nullptr) {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }

    bool isNull(void) {
        return top == nullptr;
    }
};


// queue using single stack.
class StkQ{
    stack<int> stk;
public:
    StkQ() {}
    void enqueue(int x) {
        this->stk.push(x);
    }

    void dequeue(void) {
        if(!stk.size()) {
            cout << "Queue empty" << endl;
            return;
        }
        int ele = this->stk.top();
        stk.pop();
        if(stk.empty()) {
            cout << "successful" << endl;
            return;
        }
        dequeue();
        this->stk.push(ele);
    }

    int front(void) {
        if(!stk.size()) {
            cout << "Queue empty" << endl;
            return -1;
        }
        int ele = this->stk.top();
        this->stk.pop();
        if(stk.empty()) {
            stk.push(ele);
            return ele;
        }
        int fr = front();
        this->stk.push(ele);
        return fr;
    }

    int size(void) {
        return this->stk.size();
    }
};

// void insertAtBottom(stack<int> &st, int x) {
    
//     if (st.empty()) {
//         st.push(x);
//         return;
//     }

//     // hold the top element and remove it
//     int top = st.top();
//     st.pop();

//     // recursively call to reach the bottom
//     insertAtBottom(st, x);

//     st.push(top);
// }

// // function to reverse the stack
// void reverseStack(stack<int> &st) {
    
//     if (st.empty()) return;

//     // hold the top element and remove it
//     int top = st.top();
//     st.pop();

//     // reverse the remaining stack
//     reverseStack(st);

//     // insert the held element at the bottom
//     insertAtBottom(st, top);
// }



//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
// STACK SORTING USING INBUILT STL STACK
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
#define ll long long
#define vll vector<ll>
#define forl(i, a, b, k) for (ll i = a; i < b; i += k)
#define Sort(a) sort(a.begin(), a.end());
#define MOD 1000000007
inline void solve()
{
    stack<int> st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }
    // sorting a stack function
    auto Sort_stack = [&](stack<int> &s, auto &&rec_ref) -> void
    {
        if (s.empty())
        {
            return;
        }
        int x = s.top();
        s.pop();
        rec_ref(s, rec_ref);
        stack<int> temp_stack;
        // The elements which are less than the x are placed into temp_stack;
        while (!s.empty() && x < s.top())
        {
            temp_stack.push(s.top());
            s.pop();
        }
        s.push(x);
        // Return place back the temp_stack values into the stack of s
        while (!temp_stack.empty())
        {
            s.push(temp_stack.top());
            temp_stack.pop();
        }
    };
    Sort_stack(st, Sort_stack);
    // After sorting the stack=
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
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





//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//
