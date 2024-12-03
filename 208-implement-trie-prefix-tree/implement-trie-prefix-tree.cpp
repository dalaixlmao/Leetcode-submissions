
struct node {
    node* link[26];
    int ew;
    node() {
        ew = 0;
        for (int i = 0; i < 26; i++)
            link[i] = nullptr;
    }
    void put(char c, node* n) { link[c - 'a'] = n; }
    node* get(char c) { return link[c - 'a']; }
    bool present(char c) { return link[c - 'a'] != nullptr; }
    void increaseEW() { ew++; }
};

class Trie {
public:
    node* root;
    Trie() { root = new node(); }

    void insert(string word) {
        node* x = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (!x->present(c)) {
                x->put(c, new node());
            }
            x = x->get(c);
        }
        x->increaseEW();
    }

    bool search(string word) {
        node* x = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (x->present(c)) {
                x = x->get(c);
            } else {
                return false;
            }
        }
        return x->ew;
    }

    bool startsWith(string prefix) {
        node* x = root;
        int n = prefix.size();
        for (int i = 0; i < n; i++) {
            char c = prefix[i];
            if (x->present(c)) {
                x = x->get(c);
            } else
                return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */