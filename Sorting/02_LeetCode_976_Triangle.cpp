#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i=0;i<nums.size()-2;i++)
        {
            int A=nums[i];
            int B=nums[i+1];
            int D=nums[i+2];

            if(A+B>D && A+D>B && B+D>A)
            {
                
            return A+B+D;
            }
        }
        
        return 0;
    }
};
int main()
{
    return 0;
}