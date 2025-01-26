class Solution {
public:
    int stoneGameVI(vector<int>& av, vector<int>& bv) {
        vector<pair<int,int>> v;
        for(int i = 0; i < av.size(); i++){
            v.push_back({av[i] + bv[i],i});
        }
        sort(v.begin(),v.end(),[](const pair<int,int>& a, pair<int,int>& b){
            return a.first > b.first;
        });
        int as = 0;
        int bs = 0;
        for(int i=0; i < v.size(); i++){
            if(i==0){
                as += av[v[i].second];
            }
            else if(i%2==0){
                as += av[v[i].second];
            }else{
                bs += bv[v[i].second];
            }
        }
        if(as == bs){
            return 0;
        }else if (as > bs){
            return 1;
        }
        return -1;
    }
};