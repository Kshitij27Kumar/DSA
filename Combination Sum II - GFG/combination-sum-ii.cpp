//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    void findCombination(int index, vector<int>&arr, int n, int k, vector<vector<int>>&ans, vector<int>&subans){
        if(k==0){
            ans.push_back(subans);
            return;
        }
        for(int i=index;i<n;i++){
            if(i>index&&arr[i]==arr[i-1])
                continue;
            if(arr[i]>k)
                break;
            subans.push_back(arr[i]);
            findCombination(i+1,arr,n,k-arr[i],ans,subans);
            subans.pop_back();
        }
    }
public:
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        vector<int>subans;
        findCombination(0,arr,n,k,ans,subans);
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends