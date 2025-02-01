class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
        for(auto el : edges){
            dist[el[0]][el[1]] = el[2];
            dist[el[1]][el[0]] = el[2];
        }
        for(int i = 0;i < n; i++){
            dist[i][i] = 0;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0;k < n; k++){
                    if(dist[j][i] == INT_MAX || dist[i][k] == INT_MAX){
                        continue;
                    }
                    dist[j][k] = min(dist[j][k],dist[j][i] + dist[i][k]);
                }
            }
        }
        int cntCity = INT_MAX;
        int city = -1;
        for(int i = 0; i < n; i++){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(dist[i][j] <= distanceThreshold) cnt++;
            }
            if(cnt <= cntCity){
                cntCity = cnt;
                city = i;
            }
        }
        return city;
    }
};