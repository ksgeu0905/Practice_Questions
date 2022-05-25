class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int arr[rowIndex+1][rowIndex+1];
        for(int i=0;i<=rowIndex;i++){
            arr[i][0]=1;
            arr[0][i]=1;
        }
        for(int i=1;i<=rowIndex;i++){
            for(int j=1;j<=rowIndex-i;j++){
                arr[i][j]=arr[i][j-1]+arr[i-1][j];
            }
        }
        vector<int>a;
        int row=rowIndex,col=0;
        while(row>=0){
            a.push_back(arr[row][col]);
            row--;
            col++;
        }
          
        
        return a;
    }
};