class Solution {
public:
    bool reorderedPowerOf2(int n) {
        if(n==1 || n==2 || n==4 || n==8)return true;
        map<int,int>mp;
       
        int x=16;
        while(x<=1e9){
            int y=n;
            map<int,int>mp;
            while(y>0){
                int rem=y%10;
                mp[rem]++;
                y/=10;
            }
            int t=x;
            while(t>0){
                int r=t%10;
                mp[r]--;
                t/=10;
            }
            int f=0;
            for(auto i : mp){
                if(i.second!=0){
                    f=1;
                    break;
                }
            }
            if(f==0)return true; 
            else x*=2;
        }
        return false;
    }
};