class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int,double>> cars;
        for(int i = 0; i < n; i++){
            double time = (double)(target - position[i])/speed[i];
            cars.push_back({position[i],time});
        }
        sort(cars.rbegin(),cars.rend());
        int cnt = 0;
        double lastTime = 0.0;
        for(auto &it : cars){
            double currtime = it.second;
            if(currtime > lastTime){
                lastTime = currtime;
                cnt++;
            }
        }
        return cnt;
    }
};