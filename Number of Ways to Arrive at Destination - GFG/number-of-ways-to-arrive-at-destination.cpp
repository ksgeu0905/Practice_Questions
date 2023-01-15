//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod=1e9+7;
        vector<pair<int,int>>time(n),adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            time[i].first=1e9;
            time[i].second=0;
        }
        time[0]={0,1};
        q.push({0,0});
        while(!q.empty()){
            int t = q.front().first;
            int node=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(time[it.first].first > t+it.second){
                    time[it.first].first=t+it.second;
                    time[it.first].second=1;
                    q.push({time[it.first].first,it.first});
                }
                else if(time[it.first].first==(t+it.second)){
                    time[it.first].second=(time[it.first].second+1)%mod;
                    q.push({time[it.first].first,it.first});
                }
            }
        }
        return time[n-1].second;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends