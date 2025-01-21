class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& h, vector<int>& v) {
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        int mh = 1;int mv = 1;
        int c = 1;
        for(int i = 1; i < h.size(); i++){
            if(h[i] == h[i-1] + 1){
                c++;
            }else{
                c = 1;
            }
            mh = max(mh,c);
        }
        c=1;
        for(int i = 1; i < v.size(); i++){
            if(v[i] == v[i-1] + 1){
                c++;
            }else{
                c = 1;
            }
            mv = max(mv,c);
        }
        int ans = min(mh+1,mv+1);
        return ans*ans;
    }
};