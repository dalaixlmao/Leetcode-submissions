struct Node {
    Node* link[26];
    int ew;
    Node() {
        for (int i = 0; i < 26; i++)
            link[i] = nullptr;
        ew = 0;
    }
    Node* get(char c) { return link[c - 'a']; }
    void put(char c, Node* node) { link[c - 'a'] = node; }
    bool present(char c) { return link[c - 'a'] != nullptr; }
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() { root = new Node(); }

    void addWord(string word) {
        Node* node = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (!node->present(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->ew++;
    }

    bool searchChar(Node* node, int i, string& word) {
        if (i == word.size())
            return node->ew > 0;
        if (word[i] == '.') {
            int o = 0;
            for (int j = 0; j < 26; j++) {
                if (node->present('a' + j))
                    o = o | searchChar(node->get('a' + j), i + 1, word);
            }
            return o;
        }
        if (node->present(word[i]))
            return searchChar(node->get(word[i]), i + 1, word);
        return false;
    }

    bool search(string word) {
        Node* node = root;
        return searchChar(node, 0, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */