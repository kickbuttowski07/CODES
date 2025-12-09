class Node {
public:
    int data;
    Node *next;
    Node(int val) {
        this->data = val;
        this->next = nullptr;
    }
};

class LL {
    Node *head, *tail;
    int size;
public: 
    LL() {
        head = nullptr, tail = nullptr;
        size = 0;
    }
    void insert_end(int x) {
        insert_pos(x, size);
    }

    void insert_beg(int x) {
        insert_pos(x, 0);
    }

    void insert_pos(int x, int pos) {
        Node *curr = new Node(x);
        if(pos == 0) {
            if(head == nullptr) {
                head = tail = curr;
            }
            else {
                curr->next = head;
                head = curr;
            }
        }
        else {
            int cnt = 0;
            Node *temp = head;
            while(cnt < pos - 1) {
                temp = temp->next;
                cnt++;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
        size++;
    }

    void delete_beg() {
        delete_pos(0);
    }

    void delete_end() {
        delete_pos(size - 1);
    }

    void delete_pos(int pos) {
        if(size == 0) return;
        if(pos < 0 || pos >= size) return;

        if(pos == 0) {
            // delete first node
            Node *temp = head;
            head = head->next;
            delete temp;
            if(head == nullptr) {   // list becomes empty
                tail = nullptr;
            }
        }
        else {
            // delete node at pos
            int cnt = 0;
            Node *prev = head;
            while(cnt < pos - 1) {
                prev = prev->next;
                cnt++;
            }
            Node *delNode = prev->next;
            prev->next = delNode->next;
            if(delNode == tail) {      // deleting last node
                tail = prev;
            }
            delete delNode;
        }
        size--;
    }

    void middle() {
        Node *sl = head, *fs = head;
        while(fs != nullptr && fs->next != nullptr) {
            sl = sl->next;
            fs = fs->next->next;
        }
        trav(sl);
    }

    void reverse() {
        Node *prev = nullptr;
        Node *temp = head;
        tail = head;
        while(temp != nullptr) {
            Node *front = temp;
            temp = temp->next;
            front->next = prev;
            prev = front;
        }
        head = prev;
    }

    bool is_cycle() {
        Node *sl = head, *fs = head;
        while(fs && fs -> next) {
            sl = sl->next;
            fs = fs->next->next;
            if(fs == sl) {
                return true;
            }
        }
        return false;
    }

    pair<Node*, int> loop_sp() {
        Node *sl = head, *fs = head;
        while(fs && fs -> next) {
            sl = sl->next;
            fs = fs->next->next;
            if(fs == sl) {
                sl = head;
                while(sl != fs) {
                    sl = sl->next;
                    fs = fs->next;
                }
                int cnt = 0;
                while(sl != fs) {
                    sl = sl->next;
                    cnt++;
                }
                return {fs, cnt};
            }
        }
        return {nullptr, 0};
    }

    int LL_length() {
        return size;
    }

    void LL_print() {
        trav(head);
    }
    

    void trav(Node *from) {
        Node *trav = from;
        while(trav != nullptr) {
            cout << trav->data << " ";
            trav = trav->next;
        }
        cout << endl;
    }

    bool search(int x) {
        Node *trav = head;
        while(trav != nullptr) {
            if(x == trav->data) {
                return true;
            }
            trav = trav->next;
        }
        return false;
    }
    
};

/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
// DOUBLE LINKED LIST IMPLEMENTATION, INSERTION, DELETION
#include <iostream>
using namespace std;
const int N = 2e5 + 1;
#define ll long long
#define vll vector<ll>
#define forl(i, a, b, k) for (ll i = a; i < b; i += k)
#define Sort(a) sort(a.begin(), a.end());
#define MOD 1000000007
// creation of doble linked node
struct Node_dll
{
    int data;
    Node_dll *next;
    Node_dll *prev;
};
inline void solve()
{
    int n, val;
    cin >> n;
    Node_dll *head = nullptr, *temp = nullptr, *new_node;
    head = 0;
    // creation of N nodes Linked List(double)
    while (n--)
    {
        new_node = new Node_dll();
        cin >> val;
        new_node->data = val;
        new_node->next = 0;
        if (head == nullptr)
        {
            head = temp = new_node;
        }
        else
        {
            temp->next = new_node;
            new_node->prev = temp;
            temp = new_node;
        }
    }
    auto print_DLL = [&](Node_dll *head) -> void
    {
        Node_dll *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    };
    int idx, ins_val, del_val;
    cin >> idx >> ins_val;
    // insert after nth index
    auto insert_node = [&](Node_dll *head, int idx, int ins_val) -> void //------->functional pointer simply a function works as global parameter
    {
        Node_dll *curr1 = head;
        int cn = 0;
        while (cn != idx - 1 && curr1 != nullptr) // also curr1!=nullptr
        {
            curr1 = curr1->next;
            cn++;
        }
        if (curr1 == nullptr)
        {
            cout << "out_of_bound" << endl;
        }
        Node_dll *temp1 = new Node_dll();  // new node creation to insert between the curr1 and next_node
        Node_dll *next_node = curr1->next; // the node that will be next to the inserting node after insertion
        temp1->data = ins_val;
        temp1->next = curr1->next;
        temp1->prev = curr1;
        curr1->next = temp1;
        next_node->prev = temp1;
        curr1 = temp1 = new_node = nullptr; // equaling to nullptr so that we can use them again
    };
    insert_node(head, idx, ins_val); // function calling
    cin >> idx;
    // delete the nth index
    auto delete_node = [&](Node_dll *head, int idx) -> void
    {
        Node_dll *curr2 = head, *temp2;
        int cn = 0;
        while (cn != idx - 1 && curr2 != nullptr)
        {
            temp2 = curr2;
            curr2 = curr2->next;
            cn++;
        }
        if (curr2 == nullptr)
        {
            cout << "out_of_bounds" << endl;
        }
        // Approach 1:
        Node_dll *next_node = curr2->next; // always need to access the next node in the double Linked ist
        temp2->next = curr2->next;
        next_node->prev = temp2;
        curr2->next = nullptr;
        delete curr2;    // !!!! delete parameter is present in the library
        temp2 = nullptr; // equaling to nullptr so that we can use them again
        /* Approach 2: // Here there is no use of the next_node
        curr2->next->prev=curr2->prev;
        temp2->next=curr2->next;
        curr2->next=nullptr;
        delete curr2;
        */
    };
    delete_node(head, idx);
    print_DLL(head);
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