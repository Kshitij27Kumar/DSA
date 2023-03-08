class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];//{node ,edge weight}
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;//{dist,node}
        vector<long long> dist(n, 1e15);
        vector<long long> ways(n,0);
        dist[0]=0;
        ways[0]=1;
        q.push({0,0});
        int mod=(int)(1e9 +7);
        while(!q.empty()){
            long long node=q.top().second;
            long long dis=q.top().first;
            q.pop();
            for(auto it:adj[node]){
                if(dis+it.second<dist[it.first]){
                    dist[it.first]=dis+it.second;
                    q.push({dis+it.second,it.first});
                    ways[it.first]=ways[node]%mod;
                }
                else if(dis+it.second==dist[it.first]){
                   ways[it.first]= (ways[it.first]+ways[node])%mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};
