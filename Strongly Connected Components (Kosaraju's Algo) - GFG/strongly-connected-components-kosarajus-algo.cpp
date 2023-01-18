//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	void topo(int i,vector<int>&vis,stack<int>&st,vector<int>adj[]){
	    vis[i]=1;
	    for(auto it:adj[i]){
	        if(!vis[it]){
	            topo(it,vis,st,adj);
	        }
	    }
	    st.push(i);
	}
	
	
	
	void dfs(int i,vector<int>&vis,vector<int>revadj[]){
	    vis[i]=1;
	    for(auto it:revadj[i]){
	        if(!vis[it]){
	            dfs(it,vis,revadj);
	        }
	    }
	}
	
	
	
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int>st;
        vector<int>vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topo(i,vis,st,adj);
            }
        }
        
        
        vector<int> revadj[V];
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                revadj[it].push_back(i);
            }
        }
        
        for(int i=0;i<V;i++)vis[i]=0;
        
        int ans=0;
        while(!st.empty()){
            int i=st.top();
            st.pop();
            if(!vis[i]){
                ans++;
                dfs(i,vis,revadj);
            }
        }
        return ans;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends