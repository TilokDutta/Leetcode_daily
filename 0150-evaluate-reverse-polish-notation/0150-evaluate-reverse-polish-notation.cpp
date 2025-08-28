class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        int n = tokens.size();
        for(int i = 0; i < n; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" ){
                int second = stoi(st.top()); st.pop();
                int first = stoi(st.top());st.pop();
                int ans = 0;
                if(tokens[i] == "+"){
                    ans = first + second;
                }
                if(tokens[i] == "-"){
                    ans = first - second;
                }
                if(tokens[i] == "*"){
                    ans = first * second;
                }
                if(tokens[i] == "/"){
                    ans = first / second;
                }
                st.push(to_string(ans));
            }else{
                st.push(tokens[i]);
            }
        }
        return stoi(st.top());
    }
};