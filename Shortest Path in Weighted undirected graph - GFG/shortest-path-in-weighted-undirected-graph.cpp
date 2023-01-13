//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<int>parent(n+1),dist(n+1,1e9);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<=n;i++)parent[i]=i;
        vector<pair<int,int>>adj[n+1];
        for(auto i : edges)
        {
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        dist[1]=0;
        pq.push({0,1});
        while(!pq.empty()){
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int newd=it.second+d;
                if(dist[it.first]>newd){
                    dist[it.first]=newd;
                    pq.push({newd,it.first});
                    parent[it.first]=node;
                }
            }
        }
        // for(auto it:parent){
        //     cout<<it<<" ";
        // }
        vector<int>ans;
        if(dist[n]==1e9){
            ans.push_back(-1);
            return ans;
        }
        else{
            int x=n;
            while(x!=1){
                ans.push_back(x);
                x=parent[x];
            }
            ans.push_back(1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
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