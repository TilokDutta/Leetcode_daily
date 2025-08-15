class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                st.push(s[i]);
            }else if(s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if(st.empty()) return false;
                char last = st.top();
                st.pop();
                if((s[i] == ')' && last != '(') || (s[i] == '}' && last != '{') || (s[i] == ']' && last != '[')){
                    return false;    
                }
            }
        }
        if(!st.empty()){
            return false;
        }
        return true;
    }
};