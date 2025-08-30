class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(char ch : tasks){
            mp[ch]++;
        }
        priority_queue<int> pq;
        for(auto it : mp){
            pq.push(it.second);
        }
        int time = 0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i = 0; i < n+1; i++){
                if(!pq.empty()){    
                    int freq1 = pq.top(); pq.pop();
                    temp.push_back(freq1-1);
                }
            }
            for(auto &it : temp){
                if(it > 0){
                    pq.push(it);
                }
            }
            if(pq.empty()){
                time += temp.size();
            }else{
                time += n+1;
            }
        }
        return time;
    }
};