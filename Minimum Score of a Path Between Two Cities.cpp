class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<int>>adj[n+1];
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        vector<int>vis(n+1,0);
        vis[1]=1;
        queue<int>q;
        q.push(1);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:adj[node]){
                if(!vis[it[0]]){
                    q.push(it[0]);
                    vis[it[0]]=1;
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0;i<roads.size();i++){
             if(vis[roads[i][0]]&&vis[roads[i][1]]) //1 to n is always reachable but there might be cases such as 2 is not reachable to 3 but still 1 is reachable to 4 (in the first example), i.e., 3 is disconnected node.
                ans=min(ans,roads[i][2]);
        }
        return ans;
    }
};
