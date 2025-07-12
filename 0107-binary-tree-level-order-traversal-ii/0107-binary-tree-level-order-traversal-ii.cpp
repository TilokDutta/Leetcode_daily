/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        stack<pair<TreeNode*, int>> st;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int level = q.front().second;
            q.pop();
            st.push({node,level});
            if(node->right != nullptr) q.push({node->right,level+1});
            if(node->left != nullptr) q.push({node->left,level+1});
        }
        int max  = st.top().second;
        ans.resize(max+1);
        while(!st.empty()){
            TreeNode* node = st.top().first;
            int level = st.top().second;
            st.pop();
            ans[max-level].push_back(node->val);
        }
        return ans;
    }
};