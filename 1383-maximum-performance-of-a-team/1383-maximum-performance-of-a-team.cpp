class Solution {
public:
    // class compare{
    //     public:
    //         bool operator()(pair<int,pair<int,int>> a ,pair<int,pair<int,int>> b){
    //             if(a.first<b.first)
    //                 return true;
    //             else if(a.first==b.first){
    //                 if(a.second.first<b.second.first)
    //                     return true;
    //                 else if(a.second.first==b.second.first){
    //                     if(a.second.second<b.second.second)
    //                         return true;
    //                     else
    //                         return false;
    //                 }
    //                 else
    //                     return false;
    //             }
    //             return false;
    //         }
    // };
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
//         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,compare> pq;
//         vector<pair<int,int>>temp;
        
//         for(int i=0;i<n;i++){
//             pq.push({speed[i]*efficiency[i],{efficiency[i],speed[i]}});
//         }
        
//         // while(!pq.empty()){
//         //     cout<<pq.top().first<<" "<<pq.top().second.first<<" * "<<pq.top().second.second<<endl;
//         //     pq.pop();
//         // }
        
//          int ans=INT_MIN;
//        int sum=0;
//         int mini=INT_MAX;
//         int x=k;
//         while(!pq.empty()){
//             auto it=pq.top();
//             pq.pop();
//             if(((sum + it.second.second)*min(mini,it.second.first)) > ans){
//                 if(temp.size() == k){
//                     sum=sum-temp[temp.size()-1].first;
//                     min=

//                     temp.pop_back();
//                 }
//                 sum=sum + it.second.second;
//                 mini=min(mini,it.second.first);
//                 ans=((sum*mini)%(1000000007));
                
//                 temp.push_back({it.second.second,it.second.first})
//             }
//         }
//         return ans;
        
        
        
         vector<pair<int, int>> eff_sp;
            priority_queue <int, vector<int>, greater<int> > pq_speeds;
            long sum = 0, res = 0;
            for (auto i = 0; i < n; ++i)
                eff_sp.push_back({efficiency[i], speed[i]});
            sort(begin(eff_sp), end(eff_sp));
            for (auto i = n - 1; i >= 0; --i) {
                sum += eff_sp[i].second;
                pq_speeds.push(eff_sp[i].second);
                if (pq_speeds.size() > k) {
                    sum -= pq_speeds.top();
                    pq_speeds.pop();
                }
                res = max(res, sum * eff_sp[i].first);
            }
            return res % 1000000007;
      
        
    }
}; 