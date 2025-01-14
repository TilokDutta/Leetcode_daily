class Solution {
public:
    bool request(int a,int b){
        return !(b <= 0.5 * a + 7 || b > a);
    }
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int,int> mp;
        for(auto elem : ages){
            mp[elem]++;
        }
        int res = 0;
        for(auto a : mp){
            for(auto b : mp){
                if(request(a.first,b.first)){
                    res += a.second*(b.second - (a.first == b.first ? 1:0));
                }
            }
        }
        return res;
    }
};