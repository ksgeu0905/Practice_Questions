//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            vector<int>adj[n+1];
            vector<int>indeg(n+1,0);
            for(auto it:edges){
                adj[it[0]].push_back(it[1]);
                indeg[it[1]]++;
            }
            queue<pair<int,int>>q;
            for(int i=1;i<=n;i++){
                if(indeg[i]==0){
                    q.push({i,1});
                }
            }
            vector<int>ans(n,0);
            while(!q.empty()){
                int node=q.front().first;
                int time=q.front().second;
                q.pop();
                ans[node-1]=time;
                for(auto it:adj[node]){
                    indeg[it]--;
                    if(indeg[it]==0){
                        q.push({it,time+1});
                    }
                }
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends