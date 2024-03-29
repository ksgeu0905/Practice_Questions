class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
         if(trust.empty() && n==1)
        return 1;

        vector<int> indegree(n+1,0);
        vector<int> outdegree(n+1,0); 

        // find all the indegrees and outdegrees for all the nodes
        for(auto it : trust)
        {
            indegree[it[1]]++;
            outdegree[it[0]]++;
        }

        for(int i=0;i<=n;i++)
        {
            if(outdegree[i]==0 && indegree[i]==n-1)
            {
                return i;
            }
        }

        return -1;

    }
};