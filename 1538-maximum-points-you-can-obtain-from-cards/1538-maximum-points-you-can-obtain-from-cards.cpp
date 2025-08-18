class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftsum = 0;
        int n = cardPoints.size();
        for(int i = 0; i < k; i++){
            leftsum += cardPoints[i];
        }
        int rightsum = 0;
        int right = n-1;
        int maxS = leftsum;
        for(int i = k-1; i>= 0; i--){
            leftsum -= cardPoints[i];
            rightsum += cardPoints[right];
            right--;
            maxS = max(maxS, leftsum+rightsum);
        }
        return maxS;
    }
};