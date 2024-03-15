#include<iostream>
#include<vector>
using namespace std;
void DFS(int s,vector<int>adj[],vector<bool> & arr)
{
    arr[s]=true;
    cout << s << " ";
    for(int u:adj[s])
    {
        if(!arr[u])
        DFS(u,adj,arr);
    }
    

}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<int>adj[2*n];
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>arr(2*n, false);
    int counter=0;
    for(int i=1;i<=n;i++)
    {
    if(!arr[i])
    {
    DFS(1,adj,arr);
    counter++;
    }
    }
    if(counter==1 && m==n-1 ? cout << "YES":cout << "NO");
    return 0;
}