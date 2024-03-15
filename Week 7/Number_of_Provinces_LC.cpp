//https://leetcode.com/problems/number-of-provinces/post-solution/?submissionId=1204499618


#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
void DFS(int s,vector<vector<int>> & adj,vector<bool> & arr)
{
    arr[s]=true;
    for(int u:adj[s])
    {
        if(!arr[u])
        DFS(u,adj,arr);
    }
    

}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int count=0;

        vector<vector<int>>adj(isConnected.size());

        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected.size();j++)
            {
                if(isConnected[i][j]==1)
                {
                adj[i].push_back(j);
                adj[j].push_back(i);
                }
            }
        }

        vector<bool>arr(adj.size(), false);

        for(int i=0;i<adj.size();i++)
        {
            if(!arr[i])
            {
                DFS(i,adj,arr);
                count++;
            }

        }
        return count;
        
    }
};
int main()
{
    int n;
    cin >> n;
    vector<vector<int>>isConnected(n,vector<int>(n));
    for(int i=0;i<n;i++)
   {
     for(int j=0;j<n;j++)
     {
        cin >> isConnected[i][j];
     }
   }
   Solution s;
  cout << s.findCircleNum(isConnected);
   

    
    return 0;
}