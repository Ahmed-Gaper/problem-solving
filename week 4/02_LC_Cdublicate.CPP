//https://leetcode.com/problems/contains-duplicate/submissions/

#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool Contains_Duplicate(vector<int>& nums) 
    { 
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                cout << "yes";
                return true;
            }
        }
        cout << "NO";
        return false;
       
    }
};
int main()
{
    Solution f;
   vector<int>input={1,2,3,4};
      bool check = f.Contains_Duplicate(input);
      
    return 0;
}
