class Solution {
public:
    int countCommas(int n) {
        int total = 0;
        if(n < 1000) return 0;
        // if(n < 10000){
        // }
        total = n-1000+1;
        return total;
    }
};