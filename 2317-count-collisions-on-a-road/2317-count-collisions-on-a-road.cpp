class Solution {
public:
    int countCollisions(string d) {
        stack<char> st;
        st.push(d[0]);
        int n = d.size();
        if(n == 1) return 0;
        int cnt = 0;
        for(int i = 1;i < n; i++){
            if(!st.empty() && st.top() == 'R' && d[i] == 'L'){
                cnt += 2;
                st.pop();;
                st.push('S');
            }else if (!st.empty() && d[i] == 'L' && st.top() == 'S'){
                cnt++;
            }else if(!st.empty() && d[i] == 'S' && st.top() == 'R'){
                cnt++;
                st.pop();
                st.push('S');
            }else{
                st.push(d[i]);
            }
        }
        while(!st.empty() && st.top() == 'R') // remove the leading R's
            st.pop();
        while(!st.empty()) // count the remaing R's
        {
            if(st.top() == 'R')cnt++;
            st.pop();
        }
        return cnt;
    }
};