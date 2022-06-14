// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int find(int W,int wt[],int val[],int ind,vector<vector<int>>&dp ){
        if(W<=0)
            return 0;
        if(ind<0)
            return 0;
        if(dp[W][ind]!=-1)return dp[W][ind];
        int pick=-1;
        if(wt[ind] <= W){
            pick =val[ind]+find(W-wt[ind],wt,val,ind-1,dp);
        }
        int npick=find(W,wt,val,ind-1,dp);
        return dp[W][ind]=max(pick,npick);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>> dp(n,vector<int> (W+1,0));
       for(int x=wt[0];x<=W;x++)dp[0][x]=val[0];
       for(int ind=1;ind<n;ind++){
           for(int w=1;w<=W;w++){
               int n_pick=0;
               if(ind!=0)
                   n_pick=dp[ind-1][w];
               int pick=0;
               if(ind!=0 && wt[ind]<=w){
                   pick=val[ind]+dp[ind-1][w-wt[ind]];
               }
               dp[ind][w]=max(pick,n_pick);
           }
       }
       return dp[n-1][W];
      
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends