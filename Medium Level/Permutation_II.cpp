/*
Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>> ans;
        set<vector<int>> s;
        sort(nums.begin(), nums.end());
        do {        
            s.insert(nums);
        }while (next_permutation(nums.begin(), nums.end()));
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};
*/