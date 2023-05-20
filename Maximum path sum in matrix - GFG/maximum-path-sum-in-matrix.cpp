//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        // code here
        vector<int>prev(n,0);
        int ans=-1e9;
        for(int i=0;i<n;i++){
            prev[i]=matrix[0][i];
            if(i==n-1)
                ans=max(prev[i],ans);
        }
        
        for(int i=1;i<n;i++){
            int u,dl,dr;
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                int u=matrix[i][j]+prev[j];
                if(j>0){
                    dl=matrix[i][j]+prev[j-1];
                }else{
                    dl=-1e9;
                }
                if(j<n-1){
                    dr=matrix[i][j]+prev[j+1];
                }else{
                    dr=-1e9;
                }
                curr[j]=max(u,max(dl,dr));
                if(i==n-1)
                    ans=max(ans,curr[j]);
            }
            prev=curr;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends