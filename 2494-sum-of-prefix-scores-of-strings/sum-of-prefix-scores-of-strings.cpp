struct Node{
    Node *links[26];
    int cnt=0;
    Node(){
        cnt=0;
        for(int i=0;i<26;i++)
        links[i]=NULL;
    }
    bool present(char c)
    {
        return links[c-'a']!=NULL;
    }
    Node *get(char c)
    {
        return links[c-'a'];
    }
    void put(char c, Node *node)
    {
        links[c-'a']=node;
    }
    void increment()
    {
        cnt++;
    }
};
class Trie{
    Node *root;
public:
    Trie()
    {
        root = new Node();
    }

    void insert(string s)
    {
        int n=s.size();
        Node * node = root;
        for(int i=0;i<n;i++)
        {
            if(!node->present(s[i]))
            {
                node->put(s[i], new Node);
            }
            node = node->get(s[i]);
            node->increment();
        }
    }

    int getPrf(string s)
    {
        int sm=0;
        int n = s.size();
        Node * node = root;
        for(int i=0;i<n;i++)
        {
            if(node->present(s[i]))
            {
                node = node->get(s[i]);
                sm+=node->cnt;
            }
            else{
                return sm;
            }
        }
        return sm;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n=words.size();
        Trie t;
        for(int i=0;i<n;i++)
        {
            t.insert(words[i]);
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(t.getPrf(words[i]));
        }
        return ans; 
    }
};