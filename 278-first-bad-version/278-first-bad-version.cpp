// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n==1)
            return 1;
        int st=0,en=n,mid,ans;
        while(st<=en){
            mid=st+(en-st)/2;
            if(isBadVersion(mid)){
                ans=mid;
                en=mid-1;
            }
            else{
                 st=mid+1;
            }
        }
        return ans;
    }
};