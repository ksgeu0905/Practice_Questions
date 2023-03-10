//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    bool isvalid(vector<int>&stalls,int d,int k){
        int x=1;
        int i=0,j=1;
        while(j<stalls.size()){
            if(stalls[j]-stalls[i]>=d){
                x++;
                i=j;
                j++;
            }
            else{
                j++;
            }
        }
        return x>=k;
        
    }
    int solve(int n, int k, vector<int> &stalls) {
    
        sort(stalls.begin(),stalls.end());
        int s=0,e=stalls[n-1]-stalls[0];
        int ans;
        while(s<=e){
            int mid = s+(e-s)/2;
            if(isvalid(stalls,mid,k)){
                ans = mid;
                s=mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends