class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,e=arr.size()-1;
        while(l<=e){
            int i=l+(e-l)/2;
            if(i>0 && i<arr.size()-1 && arr[i]>arr[i-1] && arr[i]>arr[i+1])
                return i;
            else if(i<arr.size()-1 && arr[i]<arr[i+1])
                l=i+1;
            else
                e=i-1;
        }
        return -1;
    }
};