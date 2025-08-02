class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> count;
        for (int x : basket1) count[x]++;
        for (int x : basket2) count[x]--;

        vector<int> extra1, extra2;
        for (auto& [num, diff] : count) {
            if (diff % 2 != 0) return -1;
            if (diff > 0) for (int i = 0; i < diff / 2; ++i) extra1.push_back(num);
            if (diff < 0) for (int i = 0; i < -diff / 2; ++i) extra2.push_back(num);
        }

        if (extra1.empty()) return 0;
        sort(extra1.begin(), extra1.end());
        sort(extra2.rbegin(), extra2.rend());
        int minVal = min(*min_element(basket1.begin(), basket1.end()), *min_element(basket2.begin(), basket2.end()));

        long long res = 0;
        for (int i = 0; i < extra1.size(); ++i) {
            res += min({extra1[i], extra2[i], 2 * minVal});
        }
        return res;
    }
};