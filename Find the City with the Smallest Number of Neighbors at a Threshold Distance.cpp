//Using Dijkstra's Algorithm

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        
        int cityNo=-1, cityCount=n;
        for(int i=0;i<n;i++){
            pq.push({0,i});
            vector<int>dist(n,1e9);
            dist[i]=0;
            while(!pq.empty()){
                auto it=pq.top();
                int d=it.first;
                int node=it.second;
                pq.pop();
                for(auto it:adj[node]){
                    int adjNode=it.first;
                    int wt=it.second;
                    if(d+wt<dist[adjNode]){
                        dist[adjNode]=d+wt;
                        pq.push({d+wt, adjNode});
                    }
                }
            }

            int count=0;
            for(int j=0;j<n;j++){
                if(dist[j]<=distanceThreshold){
                    count++;
                }
            }

            if(count<=cityCount){
                cityCount=count;
                cityNo=i;
            }
        }
        return cityNo;
    }
};
