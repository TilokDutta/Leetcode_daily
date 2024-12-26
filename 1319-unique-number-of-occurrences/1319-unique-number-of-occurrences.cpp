class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        unordered_set<int> st;
        for(auto elem : mp){
            if(st.find(elem.second) != st.end()) return false;
            st.insert(elem.second);
        }
        return true;
    }
};