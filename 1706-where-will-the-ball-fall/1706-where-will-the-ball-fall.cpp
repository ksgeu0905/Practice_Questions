class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<int> ans(m,-1);
        int x,y;
        for(int i=0;i<m;i++){
            x=0,y=i;
            while(1){
                if(x>=n){
                    if(y>=0 && y<m)ans[i]=y;
                    break;
                }
                if(y+1<m && grid[x][y]==1 && grid[x][y+1]==1){
                    x++;y++;
                }
                else if(y-1>=0 && grid[x][y]==-1 && grid[x][y-1]==-1){
                    x++;y--;
                }
                else{
                    break;
                }
            }
        }
        return ans;
    }
};