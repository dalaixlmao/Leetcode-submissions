/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==NULL)
        return {0.0};
        queue<pair<int, TreeNode*>> q;
        map<int, double> sm;
        map<int, double> sz;
        q.push({0, root});
        while (!q.empty()) {
            TreeNode* node = q.front().second;
            int lev = q.front().first;
            q.pop();
            sm[lev]+=double(node->val);
            sz[lev]+=1.0;
            if (node->left != NULL) {
                q.push({lev + 1, node->left});
            }
            if (node->right != NULL) {
                q.push({lev + 1, node->right});
            }
        }
        vector<double> ans;
        for(auto i:sm)
        {
            ans.push_back(i.second/(sz[i.first]));
        }
        return ans;

    }
};