class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        for(int i=0;i<m-1;i++){
            sort_it(mat,i,0);
        }
        for(int j=1;j<n-1;j++){
            sort_it(mat,0,j);
        }
        return mat;
    }
    void sort_it(vector<vector<int>>& mat,int i,int j){
        int m=mat.size();
        int n=mat[0].size();
        int x=i;
        int y=j;
        vector<int> v;
        while(i<m && j <n){
            v.push_back(mat[i][j]);
            i++;j++;
        }
        sort(v.begin(),v.end());
        int k=0;
        while(x<m && y< n){
            mat[x][y]=v[k++];
            x++;
            y++;
        }
    }
};