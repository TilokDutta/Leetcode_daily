class Solution {
public:
    vector<string> res;
    void f(string digits, string mapping[], string& ans, int idx){
        if(idx == digits.length()){
            res.push_back(ans);
            return;
        }
        int num = digits[idx] - '0';
        string val = mapping[num];
        for(auto elem:val){
            ans+=elem;
            f(digits,mapping,ans,idx+1);
            ans.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return res;
        string mapping[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string ans;
        f(digits,mapping,ans,0);
        return res;
    }
};