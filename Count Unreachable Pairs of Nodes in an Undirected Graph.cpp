class Solution {
private:
    void bfs(vector<int>adj[],vector<int>&vis, int n, long long &nodes, int node){
        queue<int>q;
        q.push(node);
        vis[node]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            nodes++;
            for(auto it:adj[curr]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans=0;
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n,0);
        long long nodesincomponent=0, nodestillnow=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(adj,vis,n,nodesincomponent,i);
                // cout<<i<<" "<<nodesincomponent<<" "<<nodestillnow<<endl;
                ans+=(nodesincomponent*nodestillnow);
                nodestillnow+=nodesincomponent;
                nodesincomponent=0;
            }
        }
        return ans;
    }
};
