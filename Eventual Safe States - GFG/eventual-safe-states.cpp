//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        vector<int>adjRev[n],indeg(n,0),topo;
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                adjRev[it].push_back(i);
                indeg[i]++;
            }
        }


        queue<int>q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0)
                q.push(i);
        }

        while(!q.empty()){
            int t=q.front();
            q.pop();
            topo.push_back(t);

            for(auto it : adjRev[t]){
                indeg[it]--;
                if(indeg[it]==0)
                    q.push(it);
            }
        }

        sort(topo.begin(),topo.end());
        return topo;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends