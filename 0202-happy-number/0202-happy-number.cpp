class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> mp;
        while(true){
            long long sum = 0;
            while(n != 0){
                int rem = n % 10;
                sum += rem*rem;
                n = n/10;
            }
            if(sum == 1) return true;
            if(mp.find(sum) != mp.end()){
                return false;
            }
            mp[sum] = 1;
            n = sum;
        }
        return false;
    }
};