class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        int indegree[n];
        for(int i=0;i<n;i++)
            indegree[i]=0;
        vector<int>adjRev[n];
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!indegree[i])
                q.push(i);
        }
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adjRev[node]){
                indegree[it]--;
                if(!indegree[it])
                    q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
