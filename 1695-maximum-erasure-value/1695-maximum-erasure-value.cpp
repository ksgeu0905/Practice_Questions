class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        
        int res = 0;
        int i = 0;
        unordered_map<int, int> Map;
        int sum = 0;
        
        for(int j=0;j<n;j++){
            Map[nums[j]]++; 
            sum += nums[j];
            while(i < j && Map[nums[j]] > 1){
                Map[nums[i]]--;
                sum -= nums[i++];
            }
            res = max(res, sum);
        }
        return res;
        
    }
};