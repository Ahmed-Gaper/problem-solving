#include <iostream>
#include <vector>
using namespace std;

int N, m;
vector<vector<int>> adj;
vector<int> vis;

const int NOT_VISITED = 0, IN_PROGRESS = 1, VISITED = 2;

bool IsCyclic(int n)
{
    vis[n] = IN_PROGRESS;
    for (int c : adj[n])
    {
        if (vis[c] == IN_PROGRESS)
            return true;
        else if (vis[c] == NOT_VISITED)
            if (IsCyclic(c))
                return true;
    }
    vis[n] = VISITED;
    return false;
}

int main()
{
    cin >> N >> m;
    adj.resize(N + 1);
    vis.resize(N + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    cout << IsCyclic(0);

    return 0;
}
