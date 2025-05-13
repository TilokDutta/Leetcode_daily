class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        priority_queue<int> pq;
        int n = nums.size();
        if(n == 0) return 0;
        for(int i = 0; i < n; i++){
            pq.push(nums[i]);
        }
        int largest = 1;
        int ans = 1;
        int last = pq.top();
        pq.pop();
        while(!pq.empty()){
            int curr = pq.top();
            pq.pop();
            if(last == curr){
                continue;
            }
            if(last-curr == 1){
                ans++;
            }else{
                largest = max(ans,largest);
                ans=1;
            }
            last = curr;
        }
        return max(largest,ans);
    }
};