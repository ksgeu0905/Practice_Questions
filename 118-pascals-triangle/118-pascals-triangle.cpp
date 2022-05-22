class Solution {
public:
    vector<vector<int>> generate(int numsrows) {
        int arr[numsrows][numsrows];
        for(int i=0;i<numsrows;i++){
            arr[i][0]=1;
            arr[0][i]=1;
        }
        for(int i=1;i<numsrows;i++){
            for(int j=1;j<numsrows-i;j++){
                arr[i][j]=arr[i][j-1]+arr[i-1][j];
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<numsrows;i++){
            vector<int> a;
            int row=i,col=0;
            while(row>=0){
                a.push_back(arr[row][col]);
                row--;
                col++;
            }
            ans.push_back(a);
        }
        return ans;
    }
};