#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5,M=1e6+6;
const int NOT=0,RED=1,BLUE=2;
 
int n,m;
vector<int>adj_list[N];
int colors[N];

bool iscolorable(int src)
{
    memset(colors,NOT,sizeof colors);
    queue<int>q;
    q.push(src);
    colors[src]=RED;

    while(!q.empty())
    {
        int f=q.front();
        q.pop();
        for(int chaild:adj_list[f])
        {
            if(colors[chaild]==NOT)
            {
                colors[chaild]=(colors[f]==RED ? BLUE : RED);
                q.push(chaild);
            }
            else if(colors[chaild]==colors[f])
            {
                return false;
            }
        }
    }

    return true;

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

   cout << (iscolorable(0) ? "YES" : "NO" )<< endl;

   for(int i=0;i<n;i++)
   {
    cout << i << " : " << colors[i] << endl;
   }


    return 0;
}
