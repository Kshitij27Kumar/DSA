// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    //topological sort
    // bool isCyclic(int V, vector<int> adj[]){
    //     int indeg[V]={0};
    //     for(int i=0;i<V;i++)
    //     {
    //         for(int j:adj[i])
    //         {
    //             indeg[j]++;
    //         }
    //     }
    //     int count=0;
    //     queue<int>q;
    //     for(int i=0;i<V;i++)
    //     {
    //         if(indeg[i]==0)
    //             q.push(i);
    //     }
    //     while(!q.empty())
    //     {
    //         int node=q.front();
    //         q.pop();
    //         for(int i:adj[node])
    //         {
    //             indeg[i]--;
    //             if(indeg[i]==0)
    //                 q.push(i);
    //         }
    //         count++;
    //     }
    //     return count!=V;
    // }
    //using dfs
    bool checkDFS(vector<int>adj[],int vis[], int pathVis[], int node){
        vis[node]=1;
        pathVis[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                if(checkDFS(adj,vis,pathVis,it))
                    return true;
            }
            else if(pathVis[it])
                return true;
        }
        
        pathVis[node]=0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]){
        int vis[V]={0},pathVis[V]={0};
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(checkDFS(adj,vis,pathVis,i))
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends