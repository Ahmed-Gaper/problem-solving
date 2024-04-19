// the submission on leet_code --->>>> https://leetcode.com/submissions/detail/1236830173/
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int dr[]={-1,0,0,1};
        int dc[]={0,1,-1,0};

        int n=board.size();
        int m=board[0].size();

        queue< pair<int,int>>q;
        char state[n][m];
        memset(state,'X',sizeof state);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && board[i][j]=='O')
                {
                    q.push({i,j});
                    state[i][j]='O';

                }
                else if(j==0 && board[i][j]=='O')
                {
                    q.push({i,j});
                    state[i][j]='O';

                }
                else if(j==m-1 && board[i][j]=='O')
                {
                    q.push({i,j});
                    state[i][j]='O';
          
                }
                else if(i==n-1 && board[i][j]=='O')
                {
                    q.push({i,j});
                    state[i][j]='O';
          
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
                if(board[nr][nc]=='O' && state[nr][nc]!='O')
                {
                    q.push({nr,nc});
                    state[nr][nc]='O';
                }
                }
            }
        }

        for (int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                board[i][j]=state[i][j] ;
            }
        }
        



    }
};
int main()
{
    int n,m;
    cin >> n >> m;
    vector< vector<char> >board(n,vector<char>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> board[i][j];

        }
    }
    
        Solution f;
        f.solve(board);    


    return 0;
}