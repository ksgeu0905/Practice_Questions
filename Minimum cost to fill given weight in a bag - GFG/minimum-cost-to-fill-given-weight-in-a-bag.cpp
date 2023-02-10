//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int dp[205][205];
class Solution{
		

	public:
	int find(int cost[],int N,int w,int i){
	    if(w==0)return 0;
	    if(i>=N || w<0)return 1e9;
	    if(dp[w][i]!=-1)return dp[w][i];
	    int np=find(cost,N,w,i+1);
	    int p = 1e9;
	    if(cost[i]!=-1){
	        p=cost[i]+find(cost,N,w-i-1,i);
	    }
	    return dp[w][i]=min(p,np);
	}
	int minimumCost(int cost[], int N, int W) 
	{ 
	    memset(dp,-1,sizeof(dp));
        int x=find(cost,N,W,0);
        if(x==1e9)return -1;
        return x;
	} 
};


//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends