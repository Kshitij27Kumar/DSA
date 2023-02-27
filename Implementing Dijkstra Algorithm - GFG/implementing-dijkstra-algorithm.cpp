// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // vector<int>dis(V,INT_MAX);
        // dis[S]=0;
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // pq.push({S,0});
        // while(!pq.empty())
        // {
        //     pair<int,int>p=pq.top();
        //     int node=p.first;
        //     pq.pop();
        //     for(vector<int>n:adj[node])
        //     {
        //         int next=n[0];
        //         int weight=n[1];
        //         if(dis[node]+weight<dis[next])
        //         {
        //             dis[next]=dis[node]+weight;
        //             pq.push({next,dis[next]});
        //         }
        //     }
        // }
        // return dis;
        vector<int>dis(V,INT_MAX);
        dis[S]=0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({S,0});
        while(!pq.empty()){
            pair<int,int>p=pq.top();
            int node=p.first;
            pq.pop();
            for(vector<int>n:adj[node]){
                int adjacent=n[0];
                int wt=n[1];
                if(dis[node]+wt<dis[adjacent]){
                    dis[adjacent]=dis[node]+wt;
                    pq.push({adjacent,dis[adjacent]});
                }
            }
        }
        return dis;
    }
};


// { Driver Code Starts.


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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}

  // } Driver Code Ends