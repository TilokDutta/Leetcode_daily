class Solution {
public:
    int minOperations(string s) {
        if(is_sorted(s.begin(),s.end())){
            return 0;
        }
        if(s.size() == 2) return -1;
        char mini = *min_element(s.begin(),s.end());
        char maxi = *max_element(s.begin(),s.end());
        for(int i = 0; i < s.size(); i++){
            if(s[i]  <= mini){
                mini = s[i];
            }
            if(s[i] >= maxi){
                maxi = s[i];
            }
        }
        if(mini == s[0] || maxi == s[s.size() -1]){
            return 1;
        }

        if(count(s.begin(),s.end(),mini) > 1 || count(s.begin(),s.end(),maxi) > 1){
            return 2;
        }
        if(is_sorted(s.begin(), s.end(), greater<char>()) || (s.back() == mini && s.front() == maxi)){
            return 3;
        }
        return 2;
    }
};