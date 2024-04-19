// the submission on leet_code --->>>> https://leetcode.com/submissions/detail/1236070619/



#include<bits/stdc++.h>
using namespace std;
const int N=1e+5,M=1e3+3;
int grid[N][M];

    int orangesRotting() {
    int dr[]={-1,0,0,1};
    int dc[]={0,1,-1,0};
    int num_fresh=0;
    int num_father_rotten=0;
    int num_chaildren_rotten=0;
    int min=0;
    int n = sizeof(grid) / sizeof(grid[0]);
    int m = sizeof(grid[0]) / sizeof(grid[0][0]);

    queue< pair<int,int> >q;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==2)
            {
                q.push({i,j});
                grid[i][j]=2;
                num_father_rotten++;
            }
            else if(grid[i][j]==1)
            num_fresh++;
        }
    }

    while(!q.empty())
    {
        pair<int,int> f=q.front();
        q.pop();
        int check;

        if(num_chaildren_rotten==0)
         check=0;


        for(int i=0;i<4;i++)
        {
            int nr=f.first+dr[i];
            int nc=f.second+dc[i];

            if( (nr>=0 && nr<n) && (nc>=0 && nc<m) )
            {
                if(grid[nr][nc]==1)
                {
                    q.push({nr,nc});
                    grid[nr][nc]=2;
                    check=1;
                    num_fresh--;
                    num_chaildren_rotten++;
                }
            }

        }
        num_father_rotten--;
        if(check==1 && num_father_rotten==0)
        {
        min++;
        num_father_rotten=num_chaildren_rotten;
        num_chaildren_rotten=0;
        }
        
        
    }
    return !num_fresh ? min : -1;

}

int main()
{
    
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> grid[i][j];
            
        }
    }
  int min = orangesRotting();
   cout << min << endl;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}