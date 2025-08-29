class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n = stones.size();
        for(int i = 0; i < n; i++){
            pq.push(stones[i]);
        }
        while(pq.size() > 1){
            int largest = pq.top();pq.pop();
            int slargest = pq.top();pq.pop();
            if(largest != slargest){
                pq.push(largest-slargest);
            }
        }
        return pq.size() > 0 ? pq.top() : 0;
    }
};