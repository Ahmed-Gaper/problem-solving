// the submission on leet_code --->>>>  https://leetcode.com/submissions/detail/1236101066/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int dr[]={-1,0,0,1};
        int dc[]={0,1,-1,0};



        int n=image.size();
        int m=image[0].size();

        int image_state[n][m]={0};
        int old_color=image[sr][sc];
         image[sr][sc]=color;
        image_state[sr][sc]=1;

        queue< pair<int,int> >q;
        q.push({sr,sc});

        int counter=0;
        while(!q.empty())
        {
            pair<int,int>f=q.front();
            q.pop();
            for(int i=0;i<4;i++)
            {
                int nr=f.first+dr[i];
                int nc=f.second+dc[i];

                if( (nr>=0 && nr<n) && (nc>=0 && nc<m) )
                {
                    if(image[nr][nc]==old_color && image_state[nr][nc]==0)
                    {
                        image[nr][nc]=color;
                        q.push({nr,nc});
                        image_state[nr][nc]=1;
                    }
                
                }

            }
        }

        
    return image;    
    }

};


int main()
{
    Solution f;
    int n,m;
    cin >> n >> m;
    vector<vector<int>> image(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin >> image[i][j];
        }
    }

    int sc,sr;
    cin >> sr >> sc;
    int newcolor;
    cin >> newcolor;

    image= f.floodFill(image,sr,sc,newcolor);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout <<  image[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}