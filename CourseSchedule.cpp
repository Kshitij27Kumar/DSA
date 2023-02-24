class Solution {
public:
    bool isCycle(vector<int>adj[],  int vis[], int node, int pathVis[]){
        vis[node] = 1;
        pathVis[node] = 1;
        
        for(auto it:adj[node]){
            if(vis[it] == 0){
              if( isCycle(adj, vis, it, pathVis) == true) return true;
            }
            
            else if(pathVis[it] == 1) return true;
        }
        pathVis[node] = 0;
        return false;
    }
    
    void dfs(vector<int>adj[], stack<int>&st, int vis[], int node){
        vis[node] = 1;
        
        for(auto it: adj[node]){
            if(vis[it] == 0){
            dfs(adj, st, vis, it); 
        }
       
        }
      st.push(node);
    }
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int>adj[n];
         for(auto it: prerequisites){
          adj[it[1]].push_back(it[0]);
         }
         stack<int>st;
         int vis[n];
         int pathVis[n];
         for(int i=0;i<n;i++){
             vis[i]=0;
             pathVis[i]=0;
         }
        //  first we check cycle is present or not
         for(int i=0; i<n; i++){
             if(vis[i] == 0){
               if(isCycle(adj, vis, i, pathVis) == true) return {};
             }
         }
         
         // if cycle is not present then we find the topological sort;
         for(int i=0; i<n; i++)vis[i] = 0;
         for(int i=0; i<n; i++){
                if(vis[i] == 0)
                 dfs(adj, st, vis, i);
             
         }
         return st.size()==n?true:false;
          
    }
};
