class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans(2);
        vector<pair<int,int>> arr;
        for(int i=0;i<nums.size();i++){
            for(auto j : nums[i]){
                arr.push_back({j,i});
            }
        }
        sort(arr.begin(),arr.end());
        map<int,int> mp;
        int total=0,range=INT_MAX;
        int i=0,j=0;
        while(j<arr.size()){
            mp[arr[j].second]++;
            if(mp[arr[j].second]==1){
                total++;
            }
            while(total==nums.size()){
                if((arr[j].first-arr[i].first)<range){
                    range=arr[j].first-arr[i].first;
                    ans[0]=arr[i].first;
                    ans[1]=arr[j].first;
                }
                mp[arr[i].second]--;
                if(mp[arr[i].second]==0)
                    total--;
                i++;
            }
            j++;
        }
        return ans;
    }
};