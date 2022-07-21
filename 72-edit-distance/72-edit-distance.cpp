class Solution {
public:
    int find(string &s,string &t,int i ,int j,vector<vector<int>> &dp){
        if(i<0)return j+1;
        if(j<0)return i+1;
        
        if(dp[i][j]!=-1)return dp[i][j];
        int x=0,y=0,z=0,w=0;
        
        if(s[i]==t[j]){
            x= 0 + find(s,t,i-1,j-1,dp);
        }
        else{
            y= 1 + find(s,t,i,j-1,dp); // insert
            z= 1 + find(s,t,i-1,j,dp); // delete
            w= 1 + find(s,t,i-1,j-1,dp); // replace
                
        }
        return dp[i][j]=x+min(y,min(z,w));
    }
    int minDistance(string s, string t) {
       vector<vector<int>>dp(s.length(),vector<int>(t.length(),-1));
       return find(s,t,s.length()-1,t.length()-1,dp);
    }
};