class Solution {
public:
    int findParent(vector<int>&parent, int x){
        if(parent[x]==x)
            return x;
        return parent[x]=findParent(parent,parent[x]);
    }
    void unionByRank(vector<int>&parent, vector<int>&rank, int pu, int pv){
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
        }
        else if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }
        else{
            parent[pv]=pu;
            rank[pu]++;
        }
    }

    void unionBySize(vector<int>&parent, vector<int>&size, int pu, int pv){
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V=isConnected.size();
        vector<int>parent(V), rank(V), size(V);
        for(int i=0;i<V;i++){
            parent[i]=i;
            rank[i]=0;
            size[i]=1;
        }
        
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(isConnected[i][j]==1){
                    int pu=findParent(parent,i);
                    int pv=findParent(parent,j);
                    if(pu!=pv){
                        //unionByRank(parent, rank, pu, pv);
                        unionBySize(parent,size,pu,pv);
                    }
                }
            }
        }
        
        for(int i=0;i<V;i++){
            parent[i]=findParent(parent,i);
        }

        unordered_set<int>s;
        int count=0;
        for(int i=0;i<V;i++){
            if(s.find(parent[i])==s.end()){
                count++;
                s.insert(parent[i]);
            }
        }
        return count;
    }
};
