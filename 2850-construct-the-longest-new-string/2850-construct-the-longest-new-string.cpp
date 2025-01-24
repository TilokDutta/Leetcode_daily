class Solution {
public:
    int longestString(int x, int y, int z) {
        int res = min(x,y)*2 + z;
        if(x != y) res += 1;
        return res*2;
    }
};