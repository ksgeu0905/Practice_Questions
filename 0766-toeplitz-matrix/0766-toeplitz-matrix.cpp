class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        for(int r=0;r<n;r++){
            int j=0,i=r;
            while(i<n-1 && j<m-1){
                if(matrix[i][j]!=matrix[i+1][j+1])return false;
                i++;j++;
            }
        }
        for(int c=0;c<m;c++){
            int j=c,i=0;
            while(i<n-1 && j<m-1){
                if(matrix[i][j]!=matrix[i+1][j+1])return false;
                i++;j++;
            }
        }
        return true;
    }
};