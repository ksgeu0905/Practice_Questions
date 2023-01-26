//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Disjoint{
    private:
        vector<int>rank,parent;
    public:
        Disjoint(int n){
            rank.resize(n,0);
            parent.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
            }
        }
        int findparent(int node){
            if(parent[node]==node) return node;
            return parent[node]=findparent(parent[node]);
        }
        void unionbyrank(int u,int v){
            int pu=findparent(u);
            int pv=findparent(v);
            if(pu==pv)return;
            if(rank[pu]<rank[pv]){
                parent[pu]=pv;
            }
            else if(rank[pv]<rank[pu]){
                parent[pv]=pu;
            }
            else{
                parent[pu]=pv;
                rank[pv]++;
            }
        }
};
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                edges.push_back({it[1],{i,it[0]}});
            }
        }
        Disjoint obj(V);
        sort(edges.begin(),edges.end());
        int s=0;
        for(auto it:edges){
            int w=it.first;
            int u=it.second.first;
            int v=it.second.second;
            int pu=obj.findparent(u);
            int pv=obj.findparent(v);
            if(pu!=pv){
                obj.unionbyrank(u,v);
                s+=w;
            }
        }
        return s;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends