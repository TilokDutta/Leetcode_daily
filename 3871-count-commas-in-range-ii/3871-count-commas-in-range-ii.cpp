class Solution {
public:
    long long countCommas(long long n) {
        long long total = 0;
        if(n >= 1e3) total += n-1000+1;
        if(n >= 1e6) total += (n-1000000 + 1);
        if(n >= 1e9) total += (n-1000000000 +1 );
        if(n >= 1e12) total += (n-1000000000000 +1);
        if (n >= 1e15) total += (n-1e15 + 1);
        return total;
    }
};


// class Solution {
// public:
//     long long countCommas(long long n) {
//         long long total = 0;
//         long long thresholds[] = {
//             1000LL,
//             1000000LL,
//             1000000000LL,
//             1000000000000LL,
//             1000000000000000LL
//         };

//         for (long long t : thresholds) {
//             if (n >= t) {
//                 total += (n - t + 1);
//             }
//         }

//         return total;
//     }
// };