#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1, MOD = (int)(1e9 + 7);
#define int long long
#define ll long long
#define forl(i, a, b, k) for (ll i = a; i < b; i += k)
#define all(a) a.begin(), a.end()
#define allr(a) a.rbegin(), a.rend()
#define pb push_back
    

template<typename T = int> 
class Trie{
private:
    Trie *children[26];
    bool isleaf;
    int word_cnt = 0;
    int pref_cnt = 0;

public:
    Trie(){
        isleaf = false;
        word_cnt = 0, pref_cnt = 0;
        for (int i = 0; i < 26;i++){
            children[i] = nullptr;
        }
    }

    ~Trie(){
        for (int i = 0; i < 26;i++){
            if(children[i]) {
                delete (children[i]);
            }
        }
    }

    void insert(const string s) {
        Trie *curr = this;
        for (char ch : s) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
            curr->pref_cnt++;
        }
        curr->isleaf = true;
        curr->word_cnt++;
    }

    bool search(const string s) {
        Trie *curr = this;
        for(auto ch : s){
            int idx = ch - 'a';
            if(curr->children[idx] == nullptr){
                return false;
            }
            curr = curr->chidren[idx];
        }
        return curr->isleaf;
    }

    int prefixCnt(const string s) {
        Trie *curr = this;
        for(auto ch : s){
            int idx = ch - 'a';
            if(curr->children[idx] == nullptr){
                return 0;
            }
            curr = curr->children[idx];
        }
        return curr->pref_cnt;
    }

    bool isprefix(const string s) {
        Trie *curr = this;
        for(auto ch : s){
            int idx = ch - 'a';
            if(curr->children[idx] == nullptr){
                return false;
            }
            curr = curr->children[idx];
        }
        return true;
    }

    int wordcount(const string s) {
        Trie *curr = this;
        for(auto ch : s){
            int idx = ch - 'a';
            if(curr->children[idx] == nullptr){
                return 0;
            }
            curr = curr->children[idx];
        }
        return curr->word_cnt;
    }

    int lcp(int cnt) {
        Trie* curr = this;
        int len = 0;
        while (true) {
            int next = -1;
            for (int i = 0; i < 26; i++) {
                if (curr->children[i] != nullptr && curr->children[i]->pref_cnt == cnt) {
                    if (next != -1) return len; 
                    next = i;
                }
            }
            if (next == -1) break;
            curr = curr->children[next];
            len++;
        }
        return len;
    }
};
                                    
#define F first
#define S second

template<typename T = int>
class TrieNode {
public:
    TrieNode* children[26];
    bool isLeaf;
    T value;            // Optional payload (can be used for frequencies, IDs, etc.)
    int prefixCount;    // Number of words sharing this prefix
    int wordCount;      // Number of times this exact word has been inserted

    TrieNode() {
        isLeaf = false;
        prefixCount = 0;
        wordCount = 0;
        value = T();
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }

    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            if (children[i]) delete children[i];
        }
    }

    void insert(const std::string &key, const T &val = T()) {
        TrieNode* curr = this;
        for (char ch : key) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr)
                curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
            curr->prefixCount++;
        }
        curr->isLeaf = true;
        curr->value = val;
        curr->wordCount++;
    }

    bool search(const std::string &key) const {
        const TrieNode* curr = this;
        for (char ch : key) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) return false;
            curr = curr->children[idx];
        }
        return curr->isLeaf;
    }

    bool isPrefix(const std::string &prefix) const {
        const TrieNode* curr = this;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) return false;
            curr = curr->children[idx];
        }
        return true;
    }

    int countPrefix(const std::string &prefix) const {
        const TrieNode* curr = this;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) return 0;
            curr = curr->children[idx];
        }
        return curr->prefixCount;
    }

    int getWordCount(const std::string &word) const {
        const TrieNode* curr = this;
        for (char ch : word) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) return 0;
            curr = curr->children[idx];
        }
        return curr->isLeaf ? curr->wordCount : 0;
    }

    // Optional: Get value stored at end of word
    bool getValue(const std::string &key, T &outVal) const {
        const TrieNode* curr = this;
        for (char ch : key) {
            int idx = ch - 'a';
            if (curr->children[idx] == nullptr) return false;
            curr = curr->children[idx];
        }
        if (curr->isLeaf) {
            outVal = curr->value;
            return true;
        }
        return false;
    }
};

                                    
inline void solve() {
    TrieNode<> root;
    root.insert("rakhi");
    root.insert("hello");
    root.insert("here");
    root.insert("rakesh");
    root.insert("rakhi");
    cout << root.getWordCount("rakhi") << endl;
    root.insert("heres");
    root.insert("here");
    root.insert("rakhi");
    root.search("here") ? cout << "Found\n" : cout << "Not Found\n";
    root.search("herty") ? cout << "Found\n" : cout << "Not Found\n";
    cout << root.getWordCount("rakhi") << endl;
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
            cout << "endl";
        }
    }
                
    return 0;
}
// JAI SHREE RAM