class Solution {
public:
    int find(int i,vector<int>&days,vector<int>&costs,vector<int>&dp){
        if(i==days.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int p1=1e9,p2=1e9,p3=1e9;
        int ind=i;
       
        p1=costs[0]+find(i+1,days,costs,dp);
        while(ind<days.size() &&days[ind]<days[i]+7)
            ind++;
        p2=costs[1]+find(ind,days,costs,dp);
        ind=i;
        while(ind<days.size() && days[ind]<days[i]+30)
            ind++;
        p3=costs[2]+find(ind,days,costs,dp);
        
        return dp[i]=min(p1,min(p2,p3));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>dp(days.size(),-1);
        return find(0,days,costs,dp);
    }
};