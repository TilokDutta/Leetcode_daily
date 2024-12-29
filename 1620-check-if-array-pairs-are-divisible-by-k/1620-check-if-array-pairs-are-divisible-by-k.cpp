class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int it : arr){
            it  = ((it % k) + k) % k;
            mp[it]++;
        }
        if(mp[0] % 2 != 0) return false;
        if(mp.find(0) != mp.end()) mp.erase(0);
        for(auto elem : mp){
            if(mp[elem.first] != mp[k-elem.first]) return false;
        }
        return true;
    }
};