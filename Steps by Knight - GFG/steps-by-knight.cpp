//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isvalid(int i,int j,int n){
        if(i<0 || j<0 || i>=n || j>=n)return false;
        return true;
    }
	int minStepToReachTarget(vector<int>&k,vector<int>&t,int N)
	{
	    queue<pair<int,pair<int,int>>>q;
	    vector<vector<int>>vis(N,vector<int>(N,0));
	    q.push({0,{k[0]-1,k[1]-1}});
	    vis[k[0]-1][k[1]-1]=1;
	    int a1[8]={2,2,-2,-2,1,1,-1,-1};
	    int a2[8]={1,-1,1,-1,2,-2,2,-2};
	    while(!q.empty()){
	        int step=q.front().first;
	        int i=q.front().second.first;
	        int j=q.front().second.second;
	       // cout<<step<<" "<<i<<" "<<j<<endl;
	        q.pop();
	        if(i==t[0]-1 && j==t[1]-1)return step;
	        
	        for(int z=0;z<8;z++){
	            int ni=i+a1[z],nj=j+a2[z];
	            if(isvalid(ni,nj,N) && !vis[ni][nj]){
	                vis[ni][nj]=1;
	                q.push({step+1,{ni,nj}});
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends