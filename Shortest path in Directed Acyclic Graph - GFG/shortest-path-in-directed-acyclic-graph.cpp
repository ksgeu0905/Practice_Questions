//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void dfs(int i,stack<int>&st,vector<int>&vis,vector<pair<int,int>>adj[]){
         vis[i]=1;
         for(auto it:adj[i]){
             if(!vis[it.first])dfs(it.first,st,vis,adj);
         }
         st.push(i);
     } 
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<int>vis(N,0);
        vector<pair<int,int>>adj[N];
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
        }
        stack<int>st;
        for(int i=0;i<N;i++){
            if(!vis[i])dfs(i,st,vis,adj);
        }
        vector<int>dis(N,1e9);
        dis[0]=0;
        
        while(!st.empty()){
            int n=st.top();
            st.pop();
            int d=dis[n];
            for(auto it:adj[n]){
                int node = it.first;
                if(dis[node]>it.second+d){
                    dis[node]=it.second+d;
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dis[i]==1e9)dis[i]=-1;
        }
        return dis;
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