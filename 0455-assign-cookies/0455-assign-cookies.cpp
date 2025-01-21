class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int greed = 0;
        int child = 0;
        int cnt = 0;
        while(child < g.size() && greed < s.size()){
            if(s[greed] >= g[child]){
                cnt++;
                child++;
                greed++;
            }else{
                greed++;
            }
        }
        return cnt;
    }
};