class Solution {
public:
    void helper(TreeNode* root, int low, int high){
        if(root == nullptr) return;
        while(root->left != nullptr){
            if(root->left->val < low){
                root->left = root->left->right;
            }
            else if(root->left->val > high){
                root->left = root->left->left;
            }
            else break;
        }
        while(root->right != nullptr){
            if(root->right->val > high){
                root->right = root->right->left;
            }
            else if(root->right->val < low){
                root->right = root->right->right;
            }
            else break;
        }

        helper(root->left,low,high);
        helper(root->right,low,high);
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* dummy = new TreeNode(INT_MAX);
        dummy->left = root;
        helper(dummy,low,high);
        return dummy->left;
    }
};