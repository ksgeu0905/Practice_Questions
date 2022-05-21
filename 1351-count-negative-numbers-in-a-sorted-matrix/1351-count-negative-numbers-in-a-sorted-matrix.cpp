class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int c=0;
        int n=grid[0].size();
        int m=grid.size();
        int i=0,j=n-1;
        while(i<m && j>=0){
            if(grid[i][j]<0){
                c+=m-i;
                
                j--;
            }
            else if(grid[i][j]>=0){
                i++;
            }
        }
        return c;
    }
};