class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        vector<int> sec;
        unordered_set<int> st;
        for(auto elem : mp){
            sec.push_back(elem.second);
            st.insert(elem.second);
        }
        if(sec.size() != st.size()) return false;
        return true;
    }
};