class Solution {
public:
    int helper(queue<int>& q, int k){
        if(q.size() == 1){
            return q.front();
        }
        for(int i = 1; i <= k-1; i++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        q.pop();
        return helper(q,k);  
    }
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1; i <= n; i++){
            q.push(i);
        }
        int ans = helper(q,k);
        return ans;
    }
};