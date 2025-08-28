class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        int n = temp.size();
        vector<int> ans(n,0);
        for(int i = 0; i < n; i++){
            if(!st.empty()){
                while(!st.empty() && temp[st.top()] < temp[i]){
                    int last = st.top();
                    ans[last] = i-last;
                    st.pop();
                }
            }
            st.push(i);
        }
        return ans;
    }
};