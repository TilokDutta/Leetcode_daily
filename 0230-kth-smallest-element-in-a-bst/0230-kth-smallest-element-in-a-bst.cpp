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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> sorted;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* parent = q.front();
            q.pop();
            sorted.push_back(parent->val);
            if(parent->left != nullptr){
                q.push(parent->left);
            }
            if(parent->right != nullptr){
                q.push(parent->right);
            }
        }
        sort(sorted.begin(),sorted.end());
        return sorted[k-1];
    }
};