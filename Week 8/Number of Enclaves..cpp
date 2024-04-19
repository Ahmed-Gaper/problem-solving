// the submission on leet_code --->>>> https://leetcode.com/submissions/detail/1236859753/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        int dr[]={-1,0,0,1};
        int dc[]={0,1,-1,0};
        const int oo=0x3f3f3f3f;

        int num=0;

        int n=grid.size();
        int m=grid[0].size();

        queue< pair<int,int>>q;
        int state[n][m];
        memset(state,oo,sizeof state);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                num++;
            }
        }

        for(int j=0;j<m;j++)
        {
            if(grid[0][j]==1)
            {
                q.push({0,j});
                state[0][j]=1;
                grid[0][j]=0;
                num--;
            }
        }

        for(int i=0;i<n;i++)
        {
    
            if(grid[i][0]==1)
            {
                q.push({i,0});
                state[i][0]=1;
                grid[i][0]=0;
                num--;
            }
        }

        for(int i=1;i<n;i++)
        {
            if(grid[i][m-1]==1)
            {
                q.push({i,m-1});
                state[i][m-1]=1;
                grid[i][m-1]=0;
                num--;
            }
        }

        for(int j=1;j<m-1;j++)
        {
            if(grid[n-1][j]==1)
            {
                q.push({n-1,j});
                state[n-1][j]=1;
                grid[n-1][j]=0;
                num--;
            }
        }

        while(!q.empty())
        {
            pair<int,int> f=q.front();
            q.pop();

            for(int i=0;i<4;i++)
            {
                int nr=f.first+dr[i];
                int nc=f.second+dc[i];
                if( (nr>=0 && nr<n) && (nc>=0 && nc<m) )
                {
                if(grid[nr][nc]==1 && state[nr][nc]!=1)
                {
                    q.push({nr,nc});
                    grid[nr][nc]=0;
                    state[nr][nc]=1;
                    num--;
                }
                }
            }
        }

        return num;

    
    
    }
};
int main()
{
    int n,m;
    cin >> n >> m;
    vector< vector<int> >grid(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> grid[i][j];

        }
    }
    
        Solution f;
        cout << f.numEnclaves(grid);    


    return 0;
}