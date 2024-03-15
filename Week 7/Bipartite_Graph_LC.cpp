

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
bool DFS(int s,vector<vector<int>> & adj,vector<int> & arr,int c)
{
     arr[s]=c;
    for(int u:adj[s])
    {
        if(arr[u]==-1)
        {
        if(!DFS(u,adj,arr,!c))
        {
        return false;
        }
        }
        else if(arr[s]==arr[c])
        return false;
        
    }
    return true;
    

}
    bool Bipartite_Graph(vector<vector<int>>& adj) {

        vector<int>arr(adj.size(), -1);

        for(int i=0;i<adj.size();i++)
        {
            if(arr[i]==-1)
            {
                if(!DFS(i,adj,arr,0))
                return false;
            }

        }
        return true ;
        
    }
};
int main()
{
    int n;
    cin >> n;
    vector<vector<int>>adj(2*n);
    for(int i=0;i<n;i++)
   {
     int u;
     cin >> u;
     adj[i].push_back(u);
   }
   Solution s;
  cout << s.Bipartite_Graph(adj);
   

    
    return 0;
}