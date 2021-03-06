class Solution {
public:
//     int find(vector<int>& nums,int ind,int last,vector<vector<int>> &dp){
//         if(ind==nums.size())return 0;
//         if(dp[ind][last+1]!=-1)return dp[ind][last+1];
//         int pick=INT_MIN,n_pick=INT_MIN;
        
//         n_pick=find(nums,ind+1,last,dp);
//         if(last==-1 || nums[ind]>nums[last]){
//             pick=1+find(nums,ind+1,ind,dp);
//         }
//         return dp[ind][last+1]=max(pick,n_pick);
//     }
    // int lengthOfLIS(vector<int>& nums) {
    //     int n=nums.size();
    //     vector<vector<int>>dp(n,vector<int>(n+1,-1));
    //     int x=find(nums,0,-1,dp);
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<=n;j++){
    //             cout<<dp[i][j]<<" ";
    //         }
    //         cout<<endl;
    //     }
    //     return x;
    // }
    
    
    // TABULATION
    int lengthOfLIS(vector<int>& nums) {
           int n=nums.size();
          

           vector<vector<int>> dp(n+1,vector<int>(n+1,0));
           for(int ind=n-1;ind>=0;ind--){
               for(int last=ind-1;last>=-1;last--){
                   int pick=0;
                    int n_pick=dp[ind+1][last+1];
                    if(last==-1 || nums[ind]>nums[last]){
                        pick=1+dp[ind+1][ind+1];
                    }
                    dp[ind][last+1]=max(pick,n_pick);
               }
           }
            return dp[0][0];   
       }
    
    
    
    // Using binary search
    
//        int lengthOfLIS(vector<int>& nums) {
//            int n=nums.size();
//            vector<int> temp;
//            temp.push_back(nums[0]);
//            for(int i=1;i<n;i++){
//                if(nums[i]>temp.back())
//                    temp.push_back(nums[i]);
//                else{
//                    int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
//                    temp[ind]=nums[i];
//                }
//            }
//            return temp.size();
               
//        }

};