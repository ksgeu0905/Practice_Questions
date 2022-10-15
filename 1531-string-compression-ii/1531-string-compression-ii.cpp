int dp[101][27][101][101];
class Solution {
public:
    int find(int i,int prev,int freq,int k,string &s){
        if(k<0)return 1e9;
        if(i==s.length())return 0;
        
        if(dp[i][prev][freq][k]!=-1)return dp[i][prev][freq][k];
        
        int del = find(i+1,prev,freq,k-1,s);
        int keep=0;
        if(prev == s[i]-'a'){
            if(freq==1 || freq==9 || freq==99){
                keep+=1;
            }
            keep = keep + find(i+1,prev,freq+1,k,s);
        }
        else{
            keep = 1+ find(i+1,s[i]-'a',1,k,s); 
        }
        
        return dp[i][prev][freq][k]=min(keep,del);
        
        
        
    }
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return find(0,26,0,k,s);
    }
};