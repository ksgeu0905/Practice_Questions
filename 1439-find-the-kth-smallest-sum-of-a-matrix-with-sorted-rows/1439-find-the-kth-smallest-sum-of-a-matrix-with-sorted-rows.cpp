class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        int n=a.size();
        int m=a[0].size();
        
        vector<int> temp=a[0];
        if(n==1){
            return temp[k-1];
        }
        for(int i=1;i<n;i++){
            priority_queue<int> pq;
            for(int j=0;j<m;j++){
                for(int it=0;it<temp.size();it++){
                    pq.push(temp[it]+a[i][j]);
                    if(pq.size()>k){
                        pq.pop();
                    }
                }
                
            }
            temp.clear();
            while(!pq.empty()){
                temp.push_back(pq.top());
                pq.pop();
            }
        }
        return temp[0];
    }
};