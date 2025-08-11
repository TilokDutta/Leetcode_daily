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
    int maxSum;
    int solve(TreeNode* root){
        if(root == nullptr) return 0;
        int l = solve(root->left);
        int r = solve(root->right);
        int niche_wala_achha = l + r + root->val;
        int left_wala_achha = root->val + l;
        int right_wala_achha = root->val + r;
        int koi_ek_achha = max(left_wala_achha,right_wala_achha);
        int koi_nahi_achha = root->val;
        maxSum = max({maxSum,koi_ek_achha,koi_nahi_achha,niche_wala_achha});
        return max(koi_ek_achha, koi_nahi_achha);
    }
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};