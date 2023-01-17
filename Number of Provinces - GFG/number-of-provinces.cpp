//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Disjoint{
    vector<int>rank,parent;
    public:
        Disjoint(int n){
            rank.resize(n,0);
            parent.resize(n);
            for(int i=0;i<n;i++)parent[i]=i;
        }
        
        int findparent(int node){
            if(node==parent[node]){
                return node;
            }
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
                parent[pv]=pu;
                rank[pu]++;
            }
        }
        
        int findcomp(){
            int x=0;
            for(int i=0;i<parent.size();i++){
                if(parent[i]==i)x++;
            }
            return x;
        }
};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        Disjoint obj(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1){
                    obj.unionbyrank(i,j);
                }
            }
        }
        return obj.findcomp();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends