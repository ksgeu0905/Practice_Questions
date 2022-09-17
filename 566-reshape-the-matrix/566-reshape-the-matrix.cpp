class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size(),n=mat[0].size();
        if(m*n != r*c)return mat;
        vector<vector<int>>ans(r,vector<int>(c,0));
        int i1=0,i2=0,j1=0,j2=0;
        while(1){
            ans[i2][j2]=mat[i1][j1];
            j1++;
            j2++;
            if(j1==n){
                i1++;j1=0;
            }
            if(j2==c){
                i2++;j2=0;
            }
            if(i1==m)break;
        }
        return ans;
    }
};