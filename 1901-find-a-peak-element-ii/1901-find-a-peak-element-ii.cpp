class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int j=0;
        int mx=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>mx){
                j=i;
                mx=nums[i];
            }
        }
        return j;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int i=0,j;
            vector<int> ans;
        for(int i=0;i<mat.size();i++){
            j=findPeakElement(mat[i]);
            if(i!=mat.size()-1 && mat[i][j]>mat[i+1][j]){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
            else if(i==mat.size()-1){
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }        
        }
        return ans;
    }
};