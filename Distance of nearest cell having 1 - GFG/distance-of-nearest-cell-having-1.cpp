// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int r=grid.size();
	    int c=grid[0].size();
	    vector<vector<int>>res(r,vector<int>(c,INT_MAX));
	    queue<pair<int,int>> q;
	    for(int i=0;i<r;i++)
	    {
	        for(int j=0;j<c;j++)
	        {
	            
	            if(grid[i][j]==1)
	            {
	                res[i][j]=0;
	                q.push({i,j});
	            }
	        }
	    }
	    vector<pair<int,int>> move= {{0,1},{1,0},{0,-1},{-1,0}};
	    while(!q.empty())
	    {
	        int currX=q.front().first;
	        int currY=q.front().second;
	        q.pop();
	        for(auto moves:move)
	        {
	            int x=currX+moves.first;
	            int y=currY+moves.second;
	            
	            if(x<0 || y<0 || x>=r || y>=c)
	                continue;
	            else
	            {
	                if(res[x][y]>res[currX][currY]+1)
	                {
	                    res[x][y]=res[currX][currY]+1;
	                    q.push({x,y});
	                }
	            }
	        }
	    }
	    return res;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends