class Solution {
public:
    void toposort(vector<int> adj[] , int src , stack<int> &st , vector<bool>&visited){
           visited[src] = true;
           for(auto nbr : adj[src]){
                   if(!visited[nbr]){
                          toposort(adj , nbr , st , visited);
                   }
           }
          st.push(src);
    }
    void dfs(vector<int> adj[] , int src , vector<bool> &visited){
            visited[src] = true;
            for(auto nbr : adj[src]){
                 if(!visited[nbr]){
                        dfs(adj , nbr , visited);
                 }
            }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
          vector<int> result;
          stack<int> st;
          vector<int> adj[n];
          for(int i = 0 ; i < edges.size() ; i++){
                  adj[edges[i][0]].push_back(edges[i][1]);
                  // adj[edges[i][1]].push_back(edges[i][0]);
          }
         vector<bool> visited(n , false);
         for(int i = 0 ; i < n ; i++){
                if(!visited[i])
                     toposort(adj , i , st , visited);
         }
         for(int i = 0 ; i < n ; i++) visited[i] = false;
         while(st.size()){
                int src = st.top();
                st.pop();
                if(visited[src] == false){
                      result.push_back(src);
                      dfs(adj , src , visited);
                }
         }
        return result;
    }
};