class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int n = num_people;
        vector<int> ans(n,0);
        int give = 1;
        int i = 0;
        while(candies){
            if(candies >= give){
                ans[i] += give;
                candies -= give;
            }else{
                ans[i] += candies;
                candies = 0;
            }
            give++;
            i = (i+1) % num_people;
        }
        return ans;
    }
};