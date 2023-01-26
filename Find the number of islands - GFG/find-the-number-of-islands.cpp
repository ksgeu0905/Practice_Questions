//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    bool isvalid(int &i,int &j,int &m,int &n){
        if(i<0 || j<0 || i>=m || j>=n)return false;
        return true;
    }
    void bfs(int i,int j,vector<vector<char>>&grid){
        int m=grid.size(),n=grid[0].size();
        int a1[8]={0,1,1,1,0,-1,-1,-1};
        int a2[8]={1,1,0,-1,-1,-1,0,1};
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]='0';
        while(!q.empty()){
            int a=q.front().first;
            int b=q.front().second;
            q.pop();
            for(int k=0;k<8;k++){
                int na=a+a1[k],nb=b+a2[k];
                if(isvalid(na,nb,m,n) && grid[na][nb]=='1'){
                    grid[na][nb]='0';
                    q.push({na,nb});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    ans++;
                    bfs(i,j,grid);
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends