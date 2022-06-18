/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
        vector<vector<int>> ans;
        int l,r,t;
        for(int i=1;i<=1000;i++){
            l=1,r=1000;
            while(l<=r){
                int mid=(l+r)/2;
                t=customfunction.f(i,mid);
                if(t==z){
                    vector<int> temp;
                    temp.push_back(i);
                    temp.push_back(mid);
                    ans.push_back(temp);
                    break;
                }
                else if(t>z){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
        }
        return ans;
    }
};