/*
Given an array nums of positive integers. Your task is to select some subset of nums, multiply each element by an integer and add all these numbers. The array is said to be good if you can obtain a sum of 1 from the array by any possible subset and multiplicand.

Return True if the array is good otherwise return False.

 

Example 1:

Input: nums = [12,5,7,23]
Output: true
Explanation: Pick numbers 5 and 7.
5*3 + 7*(-2) = 1
*/
#include <bits/stdc++.h>
using namespace std;
bool isGoodArray(vector<int>& nums) {
        int gcd=nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++){
            gcd=__gcd(gcd,nums[i]);
            if(gcd==1)
                return true;
        }
        return false;
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
    x=isGoodArray(v);
    if(x)
        cout<<"The array is Good "<<endl;    
    else
        cout<<"The array is not Good "<<endl;    

    return 0;
}