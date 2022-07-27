class Solution {
public:
    int histogram(vector<int>& h) {
      int n = h.size();
        int la[n];
        int ra[n];
        stack<int>s;
        
        for(int i =0;i<n;i++)
        {
            while(!s.empty() && h[i]<=h[s.top()])
            {
                s.pop();
            }
            if(s.empty()==true)
            {
                la[i]=-1;
            }
            else la[i]=s.top();
            
            s.push(i);
        }
        while(!s.empty()) s.pop();
         for(int i =n-1;i>=0;i--)
        {
            while(!s.empty() && h[i]<=h[s.top()])
            {
                s.pop();
            }
            if(s.empty()==true)
            {
                ra[i]=n;
            }
            else ra[i]=s.top();
            s.push(i);
        }
        int ans=INT_MIN;
        for(int i =0;i<n;i++)
        {
            ans = max(ans,((ra[i]-la[i]-1)*h[i]));
        }
        
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxi=INT_MIN;
        vector<int>temp(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1') temp[j]+=1;
                else temp[j]=0;
            }
          maxi=max(histogram(temp),maxi);
        }
        return maxi;
    }
};