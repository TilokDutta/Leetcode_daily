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
    bool isIdentical(TreeNode* root, TreeNode* subRoot){
        if(root == nullptr || subRoot == nullptr){
            return root == subRoot;
        }
        bool isLeftSame = isIdentical(root->left,subRoot->left);
        bool isRightSame = isIdentical(root->right,subRoot->right);
        return isLeftSame && isRightSame && root->val==subRoot->val;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* first = q.front();
            q.pop();
            if(first->val == subRoot-> val){
                if(isIdentical(first,subRoot)){
                    return true;
                }
            }
            if(first->left != nullptr){
                q.push(first->left);
            }
            if(first->right != nullptr){
                q.push(first->right);
            }
        }
        return false;
    }
};