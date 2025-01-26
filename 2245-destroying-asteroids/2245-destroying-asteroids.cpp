class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long res = mass;
        for(int i=0; i < asteroids.size(); i++){
            if(res < asteroids[i]) return false;
            res += asteroids[i];
        }
        return true;
    }
};