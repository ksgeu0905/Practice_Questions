class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int l = 0, h = n-1;
   
        while(l <= h){
            int i = l+(h-l)/2;  
        
            int mx = 0,j = 0;    
            for(int x = 0; x < m; x++){
                if(mx < mat[i][x]){
                    mx = mat[i][x];
                    j = x;
                }
            }
        
            int t = (i == 0?-1:mat[i-1][j]); 
            int b = (i == n-1?-1:mat[i+1][j]);
        
            if(mx > t && mx > b){
                return {i,j};
            }
            else if(mx > t && mx < b){
                l = i+1;
            }
            else h = i-1;
        }
    
        return {0,0};
    }
};