class Solution {
public:
    void dfs(vector<int>adj[],int vis[],int node){
        vis[node]=1;
        for(auto i:adj[node]){
            if(!vis[i])
                dfs(adj,vis,i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<int>adj[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1)
                    adj[i].push_back(j);
            }
        }
        int vis[V];
        for(int i=0;i<V;i++)
            vis[i]=0;
        int count=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                count++;
                dfs(adj,vis,i);
            }
        }
        return count;
    }
};
