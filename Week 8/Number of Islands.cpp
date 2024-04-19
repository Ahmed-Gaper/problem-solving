#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islands(vector<vector<int>>& grid) {
        int dr[]={-1,-1,-1,0,0,1,1,1};
        int dc[]={-1,0,1,-1,1,-1,0,1};
        const int oo=0x3f3f3f3f;
        int n=grid.size();
        int m=grid[0].size();
        

        int num=0;
         
        queue< pair<int,int> >q;
        int vis[n][m];
        memset(vis,oo,sizeof vis);


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                    num++;
                    
                }
            
            }
        }

        while(!q.empty())
        {
            pair<int,int> f=q.front();
            q.pop();
            for(int i=0;i<8;i++)
            {

                int nr=f.first+dr[i];
                int nc=f.second+dc[i];  
                     if( (nr>=0 && nr<n) && (nc>=0 && nc<m) )
                     {

                    if(grid[nr][nc]==1 && vis[nr][nc]==oo)
                    {
                        vis[nr][nc]=1;
                        num--;
                        vis[f.first][f.second]=2;
                    }
                     }
                
                 
            }
          
        }


        
        

        
    return num;    
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

  

    int num= f.islands(grid);
    cout << num;

    

    return 0;
}