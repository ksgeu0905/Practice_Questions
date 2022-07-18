class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>pos,neg;
        for(auto i :nums){
            if (i>0)
                pos.push_back(i);
            else
                neg.push_back(i);
            
        }
        int i=0,n=nums.size(),j=0;
        while(i<n){
            nums[i++]=pos[j];
            nums[i++]=neg[j++];
        }
        return nums;
        
    }
};