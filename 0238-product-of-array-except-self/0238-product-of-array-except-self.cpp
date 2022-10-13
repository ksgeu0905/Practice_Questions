class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> t;
        int z=0,prod=1;
        for(auto i:nums){
            if(i==0)
                z++;
            else
                prod*=i;
        }
        if(z==1){
            for(auto i: nums){
                if(i==0)
                    t.push_back(prod);
                else
                    t.push_back(0);
            }
        }
        else if(z>=2){
             for(auto i: nums)
                    t.push_back(0);
        }
        else{
            for(auto i:nums){
                t.push_back(prod/i);
            }
        }
        return t;
    }
};