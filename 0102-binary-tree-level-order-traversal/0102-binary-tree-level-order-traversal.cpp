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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr) return ans;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* n = q.front().first;
            int lev = q.front().second;
            q.pop();
            if(ans.size() == lev) ans.push_back({});
            ans[lev].push_back(n->val);
            if(n->left != nullptr){
                q.push({n->left,lev+1});
            }
            if(n->right != nullptr)
            q.push({n->right,lev+1});
        }
        return ans;
    }
};