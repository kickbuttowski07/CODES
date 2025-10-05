// IMPLEMENTATION OF STACK USING ARRAY 
#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;
#define ll long long
#define vll vector<ll>
#define forl(i, a, b, k) for (ll i = a; i < b; i += k)
#define Sort(a) sort(a.begin(), a.end());
#define MOD 1000000007
class Stack
{
    int size, top, *stack;

public:
    Stack()
    {
        top = -1; // initialising the top as -1 also when ever we push any element into arr we increment it
        size = 5;
        stack = new int[size];
    }
    void push(int val)
    {
        if (sizeof_stack() == size)
        {
            // we can't add any element
            cout << "Stack is Full" << endl;
            exit(1);
        }
        top++;
        stack[top] = val;
        cout << "elememt is pushed = " << val << endl;
    }
    void pop()
    {
        // return the value that got poped
        if (top == -1)
        {
            // we can't remove
            cout << "Stack is empty" << endl;
            exit(1);
        }
        int x = stack[top];
        top--;
        cout << "The poped value is = " << x << endl;
    }
    int top_val()
    {
        // return  the value that present on the top of the stack
        return stack[top];
    }
    int sizeof_stack()
    {
        return top + 1;
    }
};
inline void solve()
{
    Stack s;
    s.push(3);
    s.push(4);
    s.push(2);
    s.push(1);
    s.push(5);
    s.push(8);
    s.pop();
    cout << "size of stack = " << s.sizeof_stack() << endl;
    s.pop();
    s.pop();
    cout << "top = " << s.top_val() << endl;
    s.pop();
    s.pop();
    s.pop();
    s.push(100);
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
