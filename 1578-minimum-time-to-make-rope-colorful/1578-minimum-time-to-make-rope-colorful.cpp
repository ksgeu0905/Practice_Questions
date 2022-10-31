class Solution {
public:
    int minCost(string c, vector<int>& time) {
        if(c.length()==1)return 0;
        int i=0,j=1,n=c.length();
        long long sum = accumulate(time.begin(),time.end(),0);
        long long ans=0;
        while(j<n){
            int maxi = time[i];
            while(c[i]==c[j]){
                maxi = max(maxi,time[j]);
                i++;j++;
            }
            if(c[i]!=c[j]){
                ans+=maxi;
                i++;j++;
            }
        }
        
        if(c[n-1]!=c[n-2]){
            ans+=time[n-1];
        }
        return sum-ans;
    }
};