#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,M=1e3+3,oo=0x3f3f3f3f;
char grid[N][M];

int CATdis[N][M];

int n,m;

int dR[]={0,-1,0,1};
int dC[]={-1,0,1,0};

void BFSCats()
{
    queue< pair<int,int>>q;

    memset(CATdis,oo,sizeof CATdis);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='C')
            {
                CATdis[i][j]=0;
                q.push({i,j});

            }
        }
    }

    while(!q.empty())
    {
        int CATR=q.front().first;
        int CATC=q.front().second;
        q.pop();
        for(int i=0;i<4;i++)
        {
            int newR=CATR+dR[i];
            int newC=CATC+dC[i];
            if((newR<n && newR>=0) && (newC<m && newC>=0 ) && CATdis[newR][newC]==oo && grid[newR][newC]!='#')
            {
                CATdis[newR][newC]=CATdis[CATR][CATC]+1;
                q.push({newR,newC});
            }
            

        }
    }

}

int mdis[N][M];
bool BFSmouse(int MR,int MC)
{
    memset(mdis,oo,sizeof mdis);

    queue< pair<int,int>>q;
    q.push({MR,MC});
    mdis[MR][MC]=0;

    while(!q.empty())
    {
        int MOUSER=q.front().first;
        int MOUSEC=q.front().second;
        q.pop();
        
        for(int i=0;i<4;i++)
     {
            int newmr=MOUSER+dR[i];
            int newmc=MOUSEC+dC[i];

       if((newmr<n && newmr>=0) && (newmc<m && newmc>=0 ) && mdis[newmr][newmc]==oo && grid[newmr][newmc]!='#' && mdis[MOUSER][MOUSEC]+1 < CATdis[newmr][newmc])
        {

       if(grid[newmr][newmc]=='E')
       {
       return true;
       }
       mdis[newmr][newmc]=mdis[MOUSER][MOUSEC]+1;
       q.push({newmr,newmc});

       }
      
     }

    }
    return false;
}
int main()
{
    int MR,MC;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> grid[i][j];
            if(grid[i][j]=='M')
            {
                MR=i;
                MC=j;                
            }

        }
        
    }

    BFSCats();
   puts(BFSmouse(MR,MC) ? "YES" : "NO");
   cout << endl;

  



  
    return 0;
}

 