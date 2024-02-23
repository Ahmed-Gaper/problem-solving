//https://leetcode.com/problems/asteroid-collision/submissions/1183301809/
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        queue<int>q;
         for(int i=0;i<asteroids.size();i++)
        {
            q.push(asteroids.at(i));
        }
       
        while(!q.empty())
        {
            if(s.empty() || s.top()<0 || (s.top()>0 && q.front()>0) )
            {
                s.push(q.front());
                q.pop();
            }
            else
            {
                if(s.top()>q.front()*-1)
                q.pop();
                else if(s.top()==q.front()*-1)
                {
                s.pop();
                q.pop();
                }
                else
                s.pop();
            }
        }
        if(!s.empty())
      {
        vector<int>ans(s.size());
        int i=s.size()-1;
        while (!s.empty())
        {
            ans[i]=s.top();
            i--;
            s.pop(); 
        }  
        return ans;
        
      }
       else
       return {};
    }
};

int main()
{
    Solution f;
    vector<int>q={-2,-1,2};
    vector<int>ans;
    ans=f.asteroidCollision(q);
    for(int i=0;i<ans.size();i++)
    {
        cout << ans.at(i) <<" ";

    }
    return 0;
}