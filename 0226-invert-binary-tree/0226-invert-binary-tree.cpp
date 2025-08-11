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
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr) return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* parent = q.front();
            TreeNode* leftNode = nullptr;
            TreeNode* rightNode = nullptr;
            if(parent->left != nullptr){
                leftNode = parent->left;
            }
            if(parent->right != nullptr){
                rightNode = parent->right;
            }
            q.pop();
            parent->left = rightNode;
            parent->right = leftNode;
            if(parent->left != nullptr){
                q.push(parent->left);
            }
            if(parent->right != nullptr){
                q.push(parent->right);
            }
        }
        return root;
    }
};