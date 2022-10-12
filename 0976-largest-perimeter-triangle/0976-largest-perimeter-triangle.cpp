class Solution {
public:
    bool isvalid(int a,int b,int c){
        if(a+b>c && b+c>a && c+a>b)return true;
        return false;
    }
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=n-1,j=n-2,k=n-3;
        while(k>=0){
            if(isvalid(nums[i],nums[j],nums[k]))return nums[i]+nums[j]+nums[k];
            i--;
            j--;
            k--;
        }
        return 0;
    }
};