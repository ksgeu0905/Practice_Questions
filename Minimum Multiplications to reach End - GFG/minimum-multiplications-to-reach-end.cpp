//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        int mod=100000;
        vector<int>dist(100000,1e9);
        queue<pair<int,int>>q;
        dist[start]=0;
        q.push({0,start});
        while(!q.empty()){
            int step=q.front().first;
            int node=q.front().second;
            q.pop();
            if(node==end)return step;
            for(auto it:arr){
                int num=(it*node)%mod;
                if(step+1 < dist[num]){
                    dist[num]=step+1;
                    q.push({dist[num],num});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends