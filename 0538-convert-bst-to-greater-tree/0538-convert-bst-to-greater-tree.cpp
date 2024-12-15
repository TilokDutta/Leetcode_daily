class Solution {
private:
    void inorder(TreeNode* root,int &sum,vector<int> &res){
        if(root == nullptr) return;

        inorder(root->left,sum,res);
        res.push_back(root->val);
        sum += root->val;
        inorder(root->right,sum,res);
    }

    void fillorder(TreeNode* root, vector<int> rev,int& i){
        if(root == nullptr) return;

        fillorder(root->left,rev,i);
        root->val = rev[i];
        i++;
        fillorder(root->right,rev,i);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        vector<int> res;
        int sum = 0;
        inorder(root,sum,res);
        vector<int> rev;
        for(int i = 0; i < res.size(); i++){
            if(i == 0){
                rev.push_back(sum);
            }
            sum -= res[i];
            rev.push_back(sum);
        }
        int i = 0;
        fillorder(root,rev,i);
        return root;
    }
};

