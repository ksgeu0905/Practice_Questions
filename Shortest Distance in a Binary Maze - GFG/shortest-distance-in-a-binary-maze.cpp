//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool isvalid(int i,int j,int m,int n){
        if(i<0 || j<0 ||i>=m ||j>=n)return false;
        return true;
    }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> s,pair<int, int> d) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        q.push({{s.first,s.second},0});
        grid[s.first][s.second]=0;
        int a1[4]={0,0,1,-1};
        int a2[4]={1,-1,0,0};
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dis=q.front().second;
            if(i==d.first && j==d.second)return dis;
            q.pop();
            for(int k=0;k<4;k++){
                int ni=i+a1[k];
                int nj=j+a2[k];
                if(isvalid(ni,nj,m,n) && grid[ni][nj]){
                    q.push({{ni,nj},dis+1});
                    grid[ni][nj]=0;
                }
            }
            
        }
        return -1;
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends