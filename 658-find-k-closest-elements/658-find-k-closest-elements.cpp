class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        if(k==n)return arr;
        vector<int>ans;
        int j=lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int i=j-1;
        cout<<j;
        while(i>=0 && j<n){
            if(abs(arr[i]-x) <= abs(arr[j]-x)){
                ans.push_back(arr[i]);
                i--;
            }
            else if(abs(arr[i]-x) > abs(arr[j]-x)){
                ans.push_back(arr[j]);
                j++;
            }
            k--;
            if(k==0)break;
        }
        if(k!=0){
            while(i>=0 && k>0){
                ans.push_back(arr[i]);
                i--;
                k--;
            }
            while(j<n && k>0){
                ans.push_back(arr[j]);
                j++;
                k--;
            }            
        }
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};