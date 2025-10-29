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


class Mynode{
public:
    Mynode *next;
    Mynode *prev;
    int key, value;
    Mynode(int key, int value) {
        this->key = key;
        this->value = value;
        prev = next = nullptr;
    }
};

class LRUcache{
public:
    int capacity; // to check the size with map
    unordered_map<int, Mynode *> mp;
    Mynode *head;
    Mynode *tail;
    LRUcache(int capacity) {
        this->capacity = capacity;
        head = new Mynode(-1, -1);
        tail = new Mynode(-1, -1);
        head->next = tail;
        tail->prev = head;
        // 2 dummy nodes
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) {
            return -1;
        }
        Mynode *curr = mp[key];
        RemoveNode(curr);
        AddNode(curr);
        return curr->value;
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Mynode *node = mp[key];
            RemoveNode(node);
        }
        Mynode *curr = new Mynode(key, value);
        AddNode(curr);
        mp[key] = curr;
        if(mp.size() > capacity) {
            Mynode *nodetodel = tail->prev;
            mp.erase(nodetodel->key);
            RemoveNode(nodetodel);
            delete nodetodel;
        }
    }

    void AddNode(Mynode* curr) {
        // head --- curr --- x
        Mynode *nextNode = head->next;
        head->next = curr;
        curr->prev = head;
        curr->next = nextNode;
        nextNode->prev = curr;
    }

    void RemoveNode(Mynode* curr) {
        Mynode *prevNode = curr->prev;
        Mynode *nextNode = curr->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
};


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
            this->stk[top++] = val;
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
int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

bool isRightAssociative(char c) {
    return c == '^';
}
string infixToPrefix(string &s) {
    // code here
    int n=s.size();
    string ans = "\0";
    reverse(s.begin(), s.end());
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') s[i] = ')';
        else if (s[i] == ')') s[i] = '(';
    }
    stack<char>stk;
    for(int i=0;i<n;i++) {
        char c = s[i];
        if(isalnum(c)) {
            ans += c;
        }
        else if(c == '(') {
            stk.push(c);
        }
        else if(c == ')') {
            while(!stk.empty() && stk.top() != '(') {
                ans += stk.top();
                stk.pop();
            }
            if(!stk.empty()) {
                stk.pop();
            }
        }
        else{
            while (!stk.empty() && stk.top() != '(' &&
                    (prec(stk.top()) > prec(c) ||
                    (prec(stk.top()) == prec(c) && isRightAssociative(c)))) {
                ans += stk.top();
                stk.pop();
            }
            stk.push(c);
        }
    }
    while(!stk.empty()) {
        ans+=stk.top();
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
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
