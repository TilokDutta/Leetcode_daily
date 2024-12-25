class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr){
            return;
        }
        TreeNode* curr = root;
        while(curr != nullptr){
            if(curr->left != nullptr){
                TreeNode* r = curr->right;
                curr->right = curr->left;

                TreeNode* pred = curr->left;
                while(pred->right != nullptr){
                    pred = pred->right;
                }
                pred->right = r;
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
        TreeNode* temp = root;
        while(temp->right != nullptr){
            temp->left = nullptr;
            temp = temp->right;
        }
    }
};