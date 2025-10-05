// SINGLE LINKED LIST IMPLEMENTATION, INSERTION, DELETION

#include <iostream>
using namespace std;
const int N = 2e5 + 1;
#define ll long long
#define vll vector<ll>
#define forl(i, a, b, k) for (ll i = a; i < b; i += k)
#define MOD 1000000007
class Node
{
public:
    int data;
    Node *next;
};
inline void solve()
{
    int n, val;
    cin >> n;
    Node *head = nullptr, *temp = nullptr, *new_node;
    head = 0;
    // creation of N nodes Linked List(single)
    while (n--)
    {
        new_node = new Node();
        cin >> val;
        new_node->data = val;
        new_node->next = nullptr;
        if (head == nullptr)
        {
            head = temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
    }
    // print the Linked_list
    auto print_LL = [&](Node *head) -> void
    {
        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    };
    print_LL(head);
    int idx, ins_val, del_val;
    cin >> idx >> ins_val;
    // insert after nth index
    auto insert_node = [&](Node *head, int idx, int ins_val) -> void //------->functional pointer simply a function works as global parameter
    {
        Node *curr1 = head;
        int cn = 0;
        while (cn != idx - 1 && curr1 != nullptr) // also curr1 != nullptr
        {
            curr1 = curr1->next;
            cn++;
        }
        if (curr1 == nullptr)
        {
            cout << "out_of_bounds" << endl;
        }
        Node *temp1 = new Node(); // new node creation
        temp1->data = ins_val;
        temp1->next = curr1->next;
        curr1->next = temp1;
        curr1 = temp1 = nullptr; // equaling to nullptr so that we can use them again
    };
    insert_node(head, idx, ins_val); // function calling
    print_LL(head);
    cin >> idx;
    // delete at nth index
    auto delete_node = [&](Node *head, int idx) -> void
    {
        Node *curr2 = head, *temp2;
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
        temp2->next = curr2->next;
        curr2->next = nullptr;
        delete curr2;    // !!!! delete parameter is present in the library
        temp2 = nullptr; // equaling to nullptr so that we can use them again
    };
    delete_node(head, idx);
    print_LL(head);
    auto Rev_LL = [&](Node *head) -> Node *
    {
        // O(n) tc
        Node *temp = head;
        // Initialize pointer 'prev' to NULL,
        // representing the previous node
        Node *prev = NULL;

        // Traverse the list, continue till
        // 'temp' reaches the end (NULL)
        while (temp != NULL)
        {
            // Store the next node in
            // 'front' to preserve the reference
            Node *front = temp->next;

            // Reverse the direction of the
            // current node's 'next' pointer
            // to point to 'prev'
            temp->next = prev;

            // Move 'prev' to the current
            // node for the next iteration
            prev = temp;

            // Move 'temp' to the 'front' node
            // advancing the traversal
            temp = front;
        }
        // Return the new head of
        // the reversed linked list
        return prev;
    };
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