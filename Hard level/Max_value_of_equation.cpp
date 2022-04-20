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