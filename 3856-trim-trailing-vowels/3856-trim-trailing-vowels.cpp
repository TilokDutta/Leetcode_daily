class Solution {
public:
    string trimTrailingVowels(string s) {
        int n = s.size();
        bool flag = false;
        for(int i = n-1; i >= 0; i--){
            if(s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u') break;
            s.erase(s.begin() +i);
        }
        return s;
    }
};