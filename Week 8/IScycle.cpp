#include<bits/stdc++.h>
using namespace std;

int n,m;
const int N=1e5+5,M=1e3+3,oo=0x3f3f3f3f;
vector<int>adj_list[N];
int vis[N];

bool BFS(int src)
{
    queue< pair<int,int> >q;
    q.push({src,-1});
    vis[src]=1;

    while(!q.empty())
    {
        pair<int,int> f=q.front();
        q.pop();

        for(int v:adj_list[f.first])
        {
            if(vis[v]==0)
            {
                q.push({v,f.first});
                vis[v]=1;
             
            }
            else if(f.second!=v)
            {
               
                return 1;
            }

        }
    }
    return 0;
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
     puts( BFS(0)?"cycle" : "Acyclic");

   
    return 0;
}
