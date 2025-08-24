class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;
        for(int i = 0; i < n; i++){
            minPrice = min(minPrice,prices[i]);
            maxProfit = max((prices[i] - minPrice),maxProfit);
        }
        return maxProfit == INT_MIN ? 0 : maxProfit;
    }
};