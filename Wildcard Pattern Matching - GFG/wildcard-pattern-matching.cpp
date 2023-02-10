//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int dp[205][205];
    bool find(string &s1,string &s2,int i,int j){
        if(i==s1.length() && j==s2.length())return true;
        if(i==s1.length() && j!=s2.length())return false;
        if(j==s2.length()){
            while(i<s1.length()){
                if(s1[i]!='*')return false;
                i++;
            }
            return true;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int p1=false,p2=false,p3=false;
        if(s1[i]=='*'){
            p1=find(s1,s2,i+1,j+1);
            p2=find(s1,s2,i,j+1);
            p3=find(s1,s2,i+1,j);
        }
        else if(s1[i]=='?' || s1[i]==s2[j]){
            p1=find(s1,s2,i+1,j+1);
        }
        else{
            return dp[i][j]=false;
        }
        return dp[i][j]=p1||p2||p3;
    }
    int wildCard(string s1,string s2)
    {
        memset(dp,-1,sizeof(dp));
        return find(s1,s2,0,0);
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends