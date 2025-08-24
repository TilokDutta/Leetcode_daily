class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0 || n == 1) return n;
        int left = 0;
        int right = 1;
        int maxi = INT_MIN;
        set<char> st;
        st.insert(s[left]);
        while(right < n){
            while(st.count(s[right])){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxi = max(((right - left)+1),maxi);
            right++;
        }
        return maxi;
    }
};