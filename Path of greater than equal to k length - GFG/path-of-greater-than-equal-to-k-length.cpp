//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
public:
    bool dfs(int src,vector<int>&vis,vector<pair<int,int>>adj[],int k,int sum,vector<int>&pathvis){
        if(sum>=k)return true;
        vis[src]=1;
        pathvis[src]=1;
        for(auto it:adj[src]){
            if(!vis[it.first] || !pathvis[it.first]){
                if(dfs(it.first,vis,adj,k,sum+it.second,pathvis))return true;
            }
        }
        pathvis[src]=0;
        return false;
    }
    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
       vector<pair<int,int>>adj[V];
       int i=0,x=0;
       while(i<E){
           adj[a[0+x]].push_back({a[1+x],a[2+x]});
           adj[a[1+x]].push_back({a[0+x],a[2+x]});
           x+=3;
           i++;
       }
    //   for(int i=0;i<V;i++){
    //       for(auto it:adj[i]){
    //           cout<<it.first<<" "<<it.second<<", ";
    //       }
    //       cout<<endl;
    //     }
        vector<int>vis(V,0),pathvis(V,0);
        
        if(dfs(0,vis,adj,k,0,pathvis))return true;
         
        return false;
    } 
};




//{ Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends