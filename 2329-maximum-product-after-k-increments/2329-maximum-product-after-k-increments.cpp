class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod = 1e9+7;
        priority_queue<int, vector<int>, greater<int>> pq(nums.begin(),nums.end());

        while(k!=0){
            int smallest = pq.top();
            pq.pop();
            pq.push(smallest+1);
            k--;
        }
        long long res = 1;
        while(!pq.empty()){
            res = (res * pq.top())%mod;
            pq.pop();
        }
        return res;
    }
};