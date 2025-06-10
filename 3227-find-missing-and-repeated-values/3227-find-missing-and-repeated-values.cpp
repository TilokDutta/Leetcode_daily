class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& g) {
        set<int> s;
        int n = g.size();
        long long sumWithRep = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                s.insert(g[i][j]);
                sumWithRep += g[i][j];
            }
        }
        long long sumWithoutNum = 0;
        for(auto each:s){
            sumWithoutNum += each;
        }
        vector<int> ans;
        long long actualSum = (n * n *( n * n + 1))/2;
        int missing = actualSum - sumWithoutNum;
        int repeat = sumWithRep - sumWithoutNum;
        ans.push_back(repeat);
        ans.push_back(missing);

        return ans;
    }
};