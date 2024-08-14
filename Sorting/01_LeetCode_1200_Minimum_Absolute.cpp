#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int min_diff=abs(arr[0]-arr[1]);

        for(int i=1;i<arr.size()-1;i++)
        {
            int cur_diff=abs(arr[i]-arr[i+1]);
            if(cur_diff<min_diff)
            min_diff=cur_diff;
        }

        vector<vector<int>>ans;

        for(int i=0;i<arr.size()-1;i++)
        {
            int cur_diff=abs(arr[i]-arr[i+1]);
            if(cur_diff==min_diff)
            {
                vector<int>p({arr[i],arr[i+1]});
                ans.push_back(p);
            }
        }

        return ans;
        
    }
};
int main()
{
    return 0;
}