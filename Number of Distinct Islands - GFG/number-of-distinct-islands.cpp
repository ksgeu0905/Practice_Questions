//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>&vis,vector<pair<int,int>>&temp,int oi,int oj){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j]==1 || grid[i][j]==0)return;
        vis[i][j]=1;
        temp.push_back({i-oi,j-oj});
        dfs(i+1,j,grid,vis,temp,oi,oj);
        dfs(i,j+1,grid,vis,temp,oi,oj);
        dfs(i-1,j,grid,vis,temp,oi,oj);
        dfs(i,j-1,grid,vis,temp,oi,oj);
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        set<vector<pair<int,int>>>s;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    vector<pair<int,int>>temp;
                    dfs(i,j,grid,vis,temp,i,j);
                    s.insert(temp);
                }
            }
        }
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends