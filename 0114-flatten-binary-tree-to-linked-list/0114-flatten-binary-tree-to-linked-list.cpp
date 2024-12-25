class Solution {
public:
    vector<TreeNode*> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        if(root != nullptr) st.push(root);
        vector<TreeNode*> res;
        while(!st.empty()){
            TreeNode* temp = st.top();
            st.pop();
            res.push_back(temp);
            if(temp->right) st.push(temp->right);
            if(temp->left) st.push(temp->left);
        }
        return res;
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> res = preorderTraversal(root);
        int n = res.size();
        for(int i = 0; i < n-1; i++){
            res[i]->right = res[i+1];
            res[i]->left = nullptr;
        }
    }
};