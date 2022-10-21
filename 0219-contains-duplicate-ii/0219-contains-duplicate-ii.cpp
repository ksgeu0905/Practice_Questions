class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         if (nums.empty()) return false;
        unordered_set<int> set;
        for (int i = 0; i < nums.size(); ++i) {
            // maintenance window nums[i-k, i-1], remove the front element from the window
            if (i > k) set.erase(nums[i-k-1]);
            // check the duplicates in set
            if (set.find(nums[i]) != set.end()) return true;
            // add current number into the set
            set.insert(nums[i]);
        }
        return false;
    }
};