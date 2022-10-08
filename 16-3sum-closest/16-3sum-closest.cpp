class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int result = 0, max_num = INT_MAX, n = nums.size();
        sort(nums.begin(),nums.end());
        
        for(int i = 0;i <n;i++){
            
            // Continue if value at ith index is a repeating value
            if(i != 0 && nums[i] == nums[i-1])
                continue;
            
            int j = i+1;
            int k = n-1;
            
            while(j<k){
                int val = nums[i]+nums[j]+nums[k];
                if(abs(target-val) < max_num){
                    max_num = abs(target-val);
                    result = val;
                }
                
                if(val < target) j++;
                else if(val > target) k--;
                else return result;
            }
        }
        return result;
    }
};