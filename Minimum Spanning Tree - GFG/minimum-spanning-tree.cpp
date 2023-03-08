//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	vector<int>parent,rank,size;
	void initialize(int n){
	    parent.resize(n+1);
	    rank.resize(n+1,0);
	    size.resize(n+1,1);
	    for(int i=0;i<n;i++){
	        parent[i]=i;
	    }
	}
	int findParent(int x){
	    if(x==parent[x])
	        return x;
	    return parent[x]=findParent(parent[x]);
	}
	
	void unionByRank(int u, int v){
	    int uPar=findParent(u);
	    int vPar=findParent(v);
	    if(uPar==vPar)  return;
	    if(uPar<vPar){
	        parent[uPar]=vPar;
	    }
	    else if(uPar>vPar){
	        parent[vPar]=uPar;
	    }
	    else{
	        parent[uPar]=vPar;
	        rank[vPar]++;
	    }
	}
	
	void unionBySize(int u, int v){
	    int uPar=findParent(u);
	    int vPar=findParent(v);
	    if(uPar==vPar)  return;
	    if(size[uPar]<size[vPar]){
	        parent[uPar]=vPar;
	        size[vPar]+=size[uPar];
	    } else{
	        parent[vPar]=uPar;
	        size[uPar]+=size[vPar];
	    }
	}
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                int adjNode=it[0];
                int wt=it[1];
                int node=i;
                edges.push_back({wt,{node,adjNode}});
            }
        }
        
        sort(edges.begin(),edges.end());
        initialize(V);
        int mstWt=0;
        for(auto it:edges){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            
            if(findParent(u)!=findParent(v)){
                mstWt+=wt;
                //unionByRank(u,v);
                unionBySize(u,v);
            }
        }
        
        return mstWt;
        // Prim's Algorithm
        // priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        // vector<int>vis(V,0);
        // int sum=0;
        // pq.push({0,0});
        
        // while(!pq.empty()){
        //     auto it=pq.top();
        //     int wt=it.first;
        //     int node=it.second;
        //     pq.pop();
        //     if(!vis[node]){
        //         sum+=wt;
        //         vis[node]=1;
        //     }
        //     else{
        //         continue;
        //     }
        //     for(auto it:adj[node]){
        //         int adjNode=it[0];
        //         int edgeWt=it[1];
        //         if(!vis[adjNode]){
        //             pq.push({edgeWt, adjNode});
        //         }
        //     }
        // }
        
        // return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends