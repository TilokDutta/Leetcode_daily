class Solution {
public:
    void find(int start, TreeNode* root, TreeNode*& main){
        if(root == nullptr) return;
        if(root->val == start){
            main = root;
        }
        find(start,root->left,main);
        find(start,root->right,main);
    }
    void fillParent(unordered_map<TreeNode*,TreeNode*>& mp, TreeNode* root){
        if(root == nullptr) return;
        if(root->left){
            mp[root->left] = root;
        }
        if(root->right){
            mp[root->right] = root;
        }
        fillParent(mp,root->left);
        fillParent(mp,root->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* main = nullptr;
        find(start,root,main);
        queue<pair<TreeNode*,int>> q;
        q.push({main,0});
        unordered_set<TreeNode*> s;
        s.insert(main);
        unordered_map<TreeNode*,TreeNode*> mp;
        fillParent(mp,root);
        int maxlevel = INT_MIN;
        while(!q.empty()){
            TreeNode* temp = q.front().first;
            int level = q.front().second;
            maxlevel = max(maxlevel,level);
            q.pop();
            if(temp->left){
                if(s.find(temp->left) == s.end()){
                    q.push({temp->left,level+1});
                    s.insert(temp->left);
                }
            }
            if(temp->right){
                if(s.find(temp->right) == s.end()){
                    q.push({temp->right,level+1});
                    s.insert(temp->right);
                }
            }
            if(mp.find(temp) != mp.end()){
                if(s.find(mp[temp]) == s.end()){
                    q.push({mp[temp],level+1});
                    s.insert(mp[temp]);
                }
            }
        }
        return maxlevel;
    }
};