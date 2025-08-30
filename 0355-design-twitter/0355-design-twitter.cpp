class Twitter {
public:
    unordered_map<int,vector<pair<int,int>>> mp;
    unordered_map<int,unordered_set<int>> followerList;
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        mp[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto &it : mp[userId]){
            pq.push(it);
        }
        for(auto it : followerList[userId]){
            for(auto & item : mp[it]){
                pq.push(item);
            }
        }
        vector<int> ans;
        for (int i = 0; i < 10 && !pq.empty(); i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        followerList[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followerList[followerId].erase(followeeId);
        
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */