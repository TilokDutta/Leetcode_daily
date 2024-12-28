class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length()) return false;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(char ch : word1){
            mp1[ch]++;
        }
        for(char ch : word2){
            mp2[ch]++;
        }

        for(auto elem : mp1){
            if(mp2[elem.first] == 0) return false;
        }
        vector<int> freq1;
        vector<int> freq2;

        for(auto elem : mp1){
            freq1.push_back(elem.second);
        }
        for(auto elem : mp2){
            freq2.push_back(elem.second);
        }
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        for(int i = 0; i < freq1.size(); i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
};