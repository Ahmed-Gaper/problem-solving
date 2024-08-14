#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> wigglesort1(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=nums.size()-1;

        vector<int>ans;

        while(i<j)
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            cout << "NUMS[j] : " << nums[j] << endl;
        }
        return ans;
        
    }
};
int main()
{
    vector<int>q{6,4,5,1,2,3};
    Solution s;
    vector<int>ans=s.wigglesort1(q);
    for(int i=0;i<q.size();i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}