//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
      vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      {
            vector<pair<int,int>>adj[v];
            for(auto it:edges){
                adj[it[0]].push_back({it[1],it[2]});
            }
            vector<int>dist(v,-1e9);
            priority_queue<pair<int,int>>pq;
            pq.push({0,src});
            dist[src]=0;
            while(!pq.empty()){
                int node=pq.top().second;
                int d=pq.top().first;
                pq.pop();
                for(auto it:adj[node]){
                    int nd=it.second+d;
                    if(nd>dist[it.first]){
                        dist[it.first]=nd;
                        pq.push({nd,it.first});
                    }
                }
            }
            for(int i=0;i<v;i++){
                if(dist[i]==-1e9)dist[i]=INT_MIN;
            }
            return dist;
      }
};

//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends