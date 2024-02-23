//https://leetcode.com/problems/product-of-array-except-self/

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    { int n=nums.size();
        vector<int> ans(n,1);
      int l=1;
      int r=1;

      for(int i=0;i<n;i++)
      {
        ans[i] *=l;
        l *=nums[i];
      }

      for(int i=n-1;i>=0;i--)
      {
        ans[i] *=r;
        r *=nums[i];
      }

      return ans;

       
    }
};
int main()
{
    Solution f;
   vector<int>input={1,2,3,4};
      vector<int>ans = f.productExceptSelf(input);
      for (int i=0;i<ans.size();i++)
      {
        cout << ans.at(i) << " ";
      }
    return 0;
}
