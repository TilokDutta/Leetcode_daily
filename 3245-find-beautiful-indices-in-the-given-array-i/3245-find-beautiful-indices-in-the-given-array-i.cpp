class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int ns = s.size();
        int na = a.size();
        int nb = b.size();
        vector<int> inda;
        vector<int> indb;
        for(int i = 0; i < ns; i++){
            if(s.substr(i,na) == a) inda.push_back(i);
            if(s.substr(i,nb) == b) indb.push_back(i);
        }
        vector<int> res;
        for(int elem : inda){
            for(int el : indb){
                if(abs(elem - el) <= k) {
                    res.push_back(elem);
                    break;
                }
            }
        }
        return res;
    }
};