//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void dfs(int node,vector<pair<int,int>>adj[],stack<int>&st,vector<int>&vis){
         vis[node]=1;
         
         for(auto it : adj[node]){
             if(!vis[it.first])
                dfs(it.first,adj,st,vis);
         }
         st.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        stack<int>st;
        vector<pair<int,int>>adj[N];
        vector<int>vis(N,0);
        for(auto i : edges){
            adj[i[0]].push_back({i[1],i[2]});
        }
        for(int i=0;i<N;i++){
            if(!vis[i])
                dfs(0,adj,st,vis);
        }
        
        
        vector<int>dist(N,INT_MAX);
        dist[0]=0;
        while(!st.empty()){
            int top = st.top();
            int dis = dist[top];
            st.pop();
            for(auto it:adj[top]){
                dist[it.first] = min(it.second+dis,dist[it.first]);
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX)
                dist[i]=-1;
        }
        return dist;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends