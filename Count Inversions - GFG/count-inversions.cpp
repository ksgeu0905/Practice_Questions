//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void merge(long long arr[],long long s,long long mid,long long e, long long&ans){
        long long temp[e-s+1];
        int k=0,i=s,j=mid+1;
        while(i<=mid && j<=e){
            if(arr[i]>arr[j]){
                ans +=mid-i+1;
                temp[k++] = arr[j++];
            }
            else{
                temp[k++]=arr[i++];
            }
        }
        while(i<=mid){
            temp[k++]=arr[i++];
        }
        while(j<=e){
            temp[k++]=arr[j++];
        }
        int x=s;
        for(int i=0;i<e-s+1;i++){
            arr[x++] = temp[i];
        }
    }
    void mergesort(long long arr[], long long s, long long e, long long &ans){
        if(s<e){
            long long mid= s + (e-s)/2;
            mergesort(arr,s,mid,ans);
            mergesort(arr,mid+1,e,ans);
            merge(arr,s,mid,e,ans);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        long long ans = 0;
        mergesort(arr,0,N-1,ans);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends