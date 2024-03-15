#include<iostream>
#include<vector>
using namespace std;

int N,m;
vector<vector<int>>adj;
vector<bool>vis;

void DFS(int n)
{
    vis[n]=true;
    for(int c:adj[n])
    {
        if(!vis[c])
        DFS(c);
    }
    cout << n << endl;
}
int main()
{
    cin >> N >> m;
    adj.resize(N*2);
    vis.resize(N,false);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << "***********" << endl;

    for(int i=0;i<N;i++)
    {
        if(!vis[i])
        DFS(i);
    }




    return 0;
}