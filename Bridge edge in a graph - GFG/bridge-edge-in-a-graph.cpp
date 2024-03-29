//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	int timer=1;
	
    //Function to find if the given edge is a bridge in graph.
    
    bool dfs(int node,int parent,vector<int>&vis,int low[],int tin[],int c,int d,vector<int>adj[]){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node]){
            if(it==parent)continue;
            else if(vis[it]==0){
                if(dfs(it,node,vis,low,tin,c,d,adj))return true;
                low[node]=min(low[node],low[it]);
                if(low[it]>tin[node] && ((c==node && d==it)||(c==it && d==node)))return true;
            }
            else{
                low[node]=min(low[node],low[it]);
            }
        }
        return false;
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        int low[V],tin[V];
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                if(dfs(i,-1,vis,low,tin,c,d,adj))return true;;
        }
        return false;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends