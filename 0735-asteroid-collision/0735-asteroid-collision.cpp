class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> st;
        int n = a.size();
        for(int i = 0; i < n; i++){
            bool destroyed = false;
            while(!st.empty() && st.top() > 0 && a[i] < 0){
                if(abs(st.top()) < abs(a[i])){
                    st.pop();
                }else if(abs(st.top()) == abs(a[i])){
                    st.pop();
                    destroyed = true;
                    break;
                }else{
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed){
                st.push(a[i]);
            }
        }
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};