class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& arr) {
        int n=arr.size();
        int c=0;
        for(int i=0;i<n-1;i++){
            int d=arr[i+1]-arr[i];
            for(int j=i+1;j<n-1;j++){
                if(arr[j+1]-arr[j]==d)
                    c++;
                else break;
            }
        }
        return c;
    }
};