class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> real[n], fake[n];
        for(auto vec : connections){
            real[vec.front()].push_back(vec.back());
            fake[vec.back()].push_back(vec.front());
        }
        int ans = 0;
        vector<bool> vis(n);
        queue<int> q;
        q.push(0); vis[0] = true;
        while(q.size()){
            auto node = q.front(); q.pop();
            for(auto child : real[node]){
                if(vis[child]) continue;
                vis[child] = true;
                q.push(child);
                ans++;
            }
            for(auto child : fake[node]){
                if(vis[child]) continue;
                vis[child] = true;
                q.push(child);
            }
        }
        return ans;
    }
};
