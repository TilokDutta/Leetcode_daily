class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int count = 0;
         for (int num : nums) {
            mp[num]++;
        }

        // Iterate through the map and find valid pairs
        for (auto& [num, freq] : mp) {
            if (k == 0) {
                // If k == 0, count numbers that appear at least twice
                if (freq > 1) count++;
            } else {
                // Otherwise, check for num + k
                if (mp.find(num + k) != mp.end()) count++;
            }
        }
        return count;
    }
};