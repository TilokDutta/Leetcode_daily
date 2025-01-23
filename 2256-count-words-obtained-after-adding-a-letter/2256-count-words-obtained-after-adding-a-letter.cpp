class Solution {
public:
    int wordCount(vector<string>& s, vector<string>& t) {
        unordered_map<string,int> mp;
        for(auto elem : s){
            sort(elem.begin(),elem.end());
            mp[elem]++;
        }
        int cnt = 0;
        for(auto el:t){
            int n = el.size();
            for(int i = 0; i < n; i++){
                string rs = el.substr(0,i) + el.substr(i+1);
                sort(rs.begin(),rs.end());
                if(mp.find(rs) != mp.end()){
                    cnt++;
                    break;
                }
            }
        }
        return cnt;
    }
};