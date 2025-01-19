#define ll long long
class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        ll l = 1; ll r = 1e15;
        ll res = r;
        ll lcm = (1LL * divisor1*divisor2)/__gcd(divisor1,divisor2);
        while(l <= r){
            ll mid = (l+r) / 2;
            if(divisor1 == divisor2){
                ll cnt = mid - mid/divisor1;
                if(cnt >= uniqueCnt1 + uniqueCnt2){
                    res = mid;
                    r = mid - 1;
                }else{
                    l = mid+1;
                }
            }else{
                ll common = mid / lcm;
                ll c1 = mid/divisor1 - common; ll c2 = mid/divisor2 - common;
                ll z1 = uniqueCnt1; ll z2 = uniqueCnt2;
                z1 -= min(z1,c2);
                z2 -= min(z2,c1);

                ll avail = mid - (c1+c2+common);
                if(z1+z2 <= avail){
                    res = mid;
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
        }
        return res;
    }
};