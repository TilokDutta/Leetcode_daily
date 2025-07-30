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
    int maxi;
    int path(TreeNode* root){
        if(root == nullptr) return 0;
        int left_wala = path(root->left);
        int right_wala = path(root-> right);
        int koi_ek_achha = max(left_wala,right_wala) + root->val;
        int koi_nahi_achha = root->val;
        int neche_achha_milgya = left_wala+right_wala + root->val;
        maxi = max({koi_ek_achha,koi_nahi_achha,neche_achha_milgya,maxi});
        return max(koi_ek_achha,koi_nahi_achha);
    }
    int maxPathSum(TreeNode* root) {
        maxi = INT_MIN;
        path(root);
        return maxi;
    }
};