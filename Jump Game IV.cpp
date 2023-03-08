class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<int>q;
        vector<int>vis(n,0);
        vis[0]=1;
        q.push(0);
        int jumps=0;
        while(!q.empty()){
            int size=q.size();
            while(size--){
            int index=q.front();
            q.pop();
            vis[index]=1;
            if(index==n-1)
                return jumps;
            for(int idx:mp[arr[index]]){
                if(!vis[idx])
                    q.push(idx);
            }
            mp[arr[index]].clear();
            if(index>0&&!vis[index-1])
                q.push(index-1);
            if(index<n-1 && !vis[index+1])
                q.push(index+1);
            }jumps++;
        }
        return jumps;
    }
};
