//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int S, int D){
        if(9*D<=S || D==1)return "-1";
        string ans="";
        int i=0;
        while(S>9){
            ans='9'+ans;
            S-=9;
            i++;
        }
        if(i==D-1){
            ans = to_string(S)+ans;
        }
        else{
            ans = to_string(S-1)+ans;
            i++;
            while(i<D-1){
                ans='0'+ans;
                i++;
            }
            ans='1'+ans;
        }
        i=D-1;
        while(ans[i]=='9'){
            i--;
        }
        
        if(i==D-1){
            ans[i]--;
            ans[i-1]++;
        }
        else{
            ans[i]++;
            ans[i+1]--;
        }
        
        return ans;
            
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends