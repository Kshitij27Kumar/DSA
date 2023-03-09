//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DisjointSet{
    
    public:
    vector<int>parent, rank, size;
        DisjointSet(int n){
            rank.resize(n+1,0);
            size.resize(n+1,1);
            parent.resize(n+1);
            for(int i=0;i<=n;i++)
                parent[i]=i;
        }
        int findParent(int x){
            if(x==parent[x])
                return x;
            return parent[x]=findParent(parent[x]);
        }
        void unionByRank(int u, int v){
            int uPar=findParent(u);
            int vPar=findParent(v);
            if(uPar==vPar)
                return;
            if(rank[uPar]<rank[vPar]){
                parent[uPar]=vPar;
            }
            else if(rank[uPar]>rank[vPar]){
                parent[vPar]=uPar;
            }
            else{
                parent[vPar]=uPar;
                rank[uPar]++;
            }
        }
        void unionBySize(int u, int v){
            int uPar=findParent(u);
            int vPar=findParent(v);
            if(uPar==vPar)  return;
            if(size[uPar]>size[vPar]){
                parent[vPar]=uPar;
                size[uPar]+=size[vPar];
            } else{
                parent[uPar]=vPar;
                size[vPar]+=size[uPar];
            }
        }
};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        int n=accounts.size();
        unordered_map<string,int>ump;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(ump.find(mail)==ump.end()){
                    ump[mail]=i;
                }else{
                    ds.unionBySize(i,ump[mail]);
                }
            }
        }
        
        vector<string>mergedMail[n];
        for(auto it:ump){
            string mail=it.first;
            int node=ds.findParent(it.second);
            mergedMail[node].push_back(mail);
        }
        
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergedMail[i].size()==0)
                continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergedMail[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends