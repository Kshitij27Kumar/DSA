class Solution {
  public:
    void topoSort(vector<pair<int,int>>adj[], int node, stack<int>&s, int vis[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it.first]){
                topoSort(adj,it.first,s,vis);
            }
        }
        s.push(node);
    }
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int d=edges[i][2];
            adj[u].push_back({v,d});
        }
        int vis[N]={0};
        stack<int>s;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                topoSort(adj,i,s,vis);
            }
        }
        
        vector<int>dist(N);
        for(int i=0;i<N;i++)
            dist[i]=INT_MAX;
        dist[0]=0;
        while(!s.empty()){
            int node=s.top();
            s.pop();
            for(auto it:adj[node]){
                int v=it.first, wt=it.second;
                if(dist[node]!=INT_MAX){
                if(dist[node]+wt<dist[v]){
                    dist[v]=dist[node]+wt;
                }
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX)
                dist[i]=-1;
        }
        return dist;
    }
};
