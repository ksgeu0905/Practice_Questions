/*
Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

Example 1:

Input: nums = [1,2,0]
Output: 3*/
#include <bits/stdc++.h>
using namespace std;
int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=1;
        for(int i=0;i<n;i++){
            if(nums[i]>0 && nums[i]==ans)
                ans++;
        }
        return ans;
}
int main(){
    int n,x;
    cout<<"Enter size of array: ";
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        cin>>x;
        v.push_back(x);
    }
    x=firstMissingPositive(v);
    cout<<"First missing Positive is: "<<x<<endl;
    return 0;
}