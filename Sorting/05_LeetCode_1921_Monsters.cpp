#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int size=dist.size();
        vector<int>arrival_time(size);
        for(int i=0;i<size;i++)
        {
            if(dist[i]%speed[i]==0)
            arrival_time[i]=dist[i]/speed[i];
            else
            arrival_time[i]=(dist[i]/speed[i])+1;
        }
        int killed=0;
        sort(arrival_time.begin(),arrival_time.end());

        for(int t=0;t<size && arrival_time[t]>t;t++)
        {
            killed++;
        }
        return killed;
    
        
    }
};
int main()
{
    vector<int>dis{4,2,8};
    vector<int>speed{2,1,4};
    Solution s;
     cout << s.eliminateMaximum(dis,speed);
    
    return 0;
}