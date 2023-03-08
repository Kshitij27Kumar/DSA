class Solution {
public:
    int MST(vector<pair<int,int>>adj[], int n){
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<int>vis(n,0);
        int sum=0;
        pq.push({0,0});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int wt=it.first;
            if(vis[node])
                continue;
            sum+=wt;
            vis[node]=1;
            for(auto it:adj[node]){
                int adjNode=it.first;
                int edgeWt=it.second;
                if(!vis[adjNode]){
                    pq.push({edgeWt, adjNode});
                }
            }
        }
        return sum;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,int>>adj[n];
        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=0;j<n;j++){
                
                if(i!=j){
                    int x2=points[j][0];
                    int y2=points[j][1];
                    int dist=abs(y2-y1)+abs(x2-x1);
                    adj[i].push_back({j,dist});
                }
            }
        }

        return MST(adj,n);
    }
};
