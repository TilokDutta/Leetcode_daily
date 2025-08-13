class Solution {
public:
    TreeNode* solve(vector<int> &inorder, vector<int> &postorder,
                    int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) return nullptr;

        // Root from postorder
        TreeNode* root = new TreeNode(postorder[postEnd]);

        // Find root in inorder
        int idx = -1;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == root->val) {
                idx = i;
                break;
            }
        }

        int leftSize = idx - inStart;

        // Build subtrees
        root->left  = solve(inorder, postorder, inStart, idx - 1,
                            postStart, postStart + leftSize - 1);
        root->right = solve(inorder, postorder, idx + 1, inEnd,
                            postStart + leftSize, postEnd - 1);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return solve(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};
