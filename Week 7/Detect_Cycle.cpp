#include<iostream>
#include<vector>
using namespace std;

int n,m;
vector<vector<int>>adj;
vector<bool>arr(false);


bool IsCyclic(int s,int p)
{
    arr[s]=true;
    for(int v:adj[s])
    {
        if(arr[v] && v!=p )
        return true;
        else if(!arr[v])
        if(IsCyclic(v,s)) return true;
    }
    return false;


}
int main()
{ 
    cin >> n >> m;
    adj.resize( 2*n);
    arr.resize( 2*n, false);



    
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << IsCyclic(1,-1);

    return 0;
}