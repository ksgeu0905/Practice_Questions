//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int kadene(vector<int>&arr){
        int maxi=INT_MIN,curr=0;
        for(int i=0;i<arr.size();i++){
            curr+=arr[i];
            maxi=max(maxi,curr);
            curr=max(curr,0);
        }
        return maxi;
    }
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        vector<int>arr(R,0);
        int maxi=INT_MIN;
        for(int i=0;i<C;i++){
            for(int j=i;j<C;j++){
                for(int k=0;k<R;k++){
                    arr[k]+=M[k][j];
                }
                maxi=max(maxi,kadene(arr));
            }
            for(int k=0;k<R;k++)arr[k]=0;
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends