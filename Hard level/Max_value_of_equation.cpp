/*
You are given an array points containing the coordinates of points on a 2D plane, sorted by the x-values, where points[i] = [xi, yi] such that xi < xj for all 1 <= i < j <= points.length. You are also given an integer k.

Return the maximum value of the equation yi + yj + |xi - xj| where |xi - xj| <= k and 1 <= i < j <= points.length.

It is guaranteed that there exists at least one pair of points that satisfy the constraint |xi - xj| <= k.

 

Example 1:

Input: points = [[1,3],[2,0],[5,10],[6,-10]], k = 1
Output: 4
Explanation: The first two points satisfy the condition |xi - xj| <= 1 and if we calculate the equation we get 3 + 0 + |1 - 2| = 4. Third and fourth points also satisfy the condition and give a value of 10 + -10 + |5 - 6| = 1.
No other pairs satisfy the condition, so we return the max of 4 and 1.
*/
#include <bits/stdc++.h>
using namespace std;
int findMaxValueOfEquation(vector<vector<int>>& arr, int k) {
        int i=0;
        int maxi=INT_MIN;
        int n=arr.size();
        priority_queue<pair<int,int>> p;
        for(i=0;i<n;i++){
            while(!p.empty() && arr[i][0]-p.top().second>k){
                p.pop();
            }
            if(!p.empty() && arr[i][0]-p.top().second<=k){
                maxi=max(maxi,p.top().first+arr[i][0]+arr[i][1]);
            }
            p.push({arr[i][1]-arr[i][0],arr[i][0]});
        }
        return maxi;
}
int main(){
    int k,n;
    vector<vector<int>>arr;
    cout<<"Enter no of pairs: ";
    cin>>n;
    int a,b;
    cout<<"Enter pairs: \n";
    while(n--){
        vector<int>temp;
        cin>>a>>b;
        temp.push_back(a);
        temp.push_back(b);
        arr.push_back(temp);
    }
    cout<<"Enter the value of key: ";
    cin>>k;
    int maxi=findMaxValueOfEquation(arr,k);
    cout<<"Max Value of equation is: "<<maxi;
    return 0;
}