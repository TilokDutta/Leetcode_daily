class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i = 0; i < flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,INT_MAX);
        dist[src] = 0;
        while(!q.empty()){
            int node = q.front().second.first;
            int stop = q.front().second.second;
            int price = q.front().first;
            q.pop();
            if(stop > k) continue;
            for(auto it : adj[node]){
                int adjnode = it.first;
                int adjprice = it.second;
                if(adjprice+ price < dist[adjnode] && stop <= k){
                    dist[adjnode] = adjprice+price;
                    q.push({adjprice+price,{adjnode,stop+1}});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};