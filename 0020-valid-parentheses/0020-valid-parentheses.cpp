class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        stack<int> st;
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }else{                
                if(st.empty()) return false;
                char last = st.top(); st.pop();
                if((s[i] == '}' && last != '{') || (s[i] == ']' && last != '[') || (s[i] == ')' && last != '(')){
                    return false;
                }
            }
        }
        if(!st.empty()) return false;
        return true;
    }
};