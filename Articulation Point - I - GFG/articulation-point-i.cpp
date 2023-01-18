//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    int timer=1;
  public:
  void dfs(int node,int parent,vector<int>&vis,int tin[],int low[],set<int>&s,vector<int>adj[]){
      vis[node]=1;
      low[node]=tin[node]=timer;
      timer++;
      int child=0;
      for(auto it:adj[node]){
          if(it==parent)continue;
          if(!vis[it]){
              dfs(it,node,vis,tin,low,s,adj);
              low[node]=min(low[node],low[it]);
              
              if(low[it]>=tin[node] && parent!=-1)s.insert(node);
              
              child++;
          }
          else{
              low[node]=min(low[node],tin[it]);
          }
      }
      if(child>1 && parent==-1){
          s.insert(node);
      }
  }
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int>vis(n,0);
        int tin[n],low[n];
        vector<int>ans;
        set<int>s;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,vis,tin,low,s,adj);
            }
        }
        for(auto it:s){
            ans.push_back(it);
        }
        if(ans.size()==0)return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends