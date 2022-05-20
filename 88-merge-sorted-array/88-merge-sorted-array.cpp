class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int k = 0;
        int j = 0;
        vector<int>num(m+n);
        while(i<m && k<n)
        {
            if(nums1[i]<nums2[k])
                num[j++] = nums1[i++];
            else if(nums1[i]>=nums2[k])
            {
                num[j++] = nums2[k++];
            }
        }
        for(;i<m;i++)
            num[j++] = nums1[i];
        for(;k<n;k++)
            num[j++]= nums2[k];
        
        nums1=num;
        
       
    }
};