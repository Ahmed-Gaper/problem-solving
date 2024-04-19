#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& grid) {
        int dr[]={-1,0,0,1};
        int dc[]={0,1,-1,0};
        const int oo=0x3f3f3f3f;
        int n=grid.size();
        int m=grid[0].size();

      

        queue< pair<int,int> >q;

        vector<vector<int>>dis(n,vector<int>(m,oo));

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    dis[i][j]=0;
                    q.push({i,j});
                }
            
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
                    if(grid[nr][nc]==0 && dis[nr][nc]==oo)
                    {
                        dis[nr][nc]=dis[f.first][f.second]+1;
                        q.push({nr,nc});
                    }
                   

                
                 }
            }
          
        }



        
        

        
    return dis;    
    }

};


int main()
{
    Solution f;
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> grid[i][j];
        }
    }

  

    grid= f.floodFill(grid);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout <<  grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}