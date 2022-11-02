#define mod 1000000007
class Solution {
public:
    int countHousePlacements(int n) {
       long long x = 2,y=3;
        if(n==1)return 4;
        if(n==2)return 9;
       for(int i=3;i<=n;i++){
           long long t = (x+y)%mod;
           x=y;
           y=t;
       } 
       return (y%mod*y%mod)%mod;
    }
};