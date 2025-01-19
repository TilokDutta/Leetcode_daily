class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<string>> mp;

        // Group access times by employee
        for (const auto& access : access_times) {
            mp[access[0]].push_back(access[1]);
        }

        vector<string> res;

        for (auto& [employee, times] : mp) {
            if (times.size() >= 3) {
                sort(times.begin(), times.end()); 

                for (size_t i = 0; i <= times.size() - 3; i++) {
                    int time1 = stoi(times[i].substr(0, 2)) * 60 + stoi(times[i].substr(2, 2));
                    int time2 = stoi(times[i + 2].substr(0, 2)) * 60 + stoi(times[i + 2].substr(2, 2));

                    if (time1 != 5 && time1 != 1430 && time2 != 5 && time2 != 1430 && (time2 - time1) < 60) {
                        res.push_back(employee);
                        break; 
                    }
                }
            }
        }

        return res;
    }
};
