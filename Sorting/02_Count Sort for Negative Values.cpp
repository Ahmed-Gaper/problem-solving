// >> https://leetcode.com/problems/sort-an-array/
#include<bits/stdc++.h>
using namespace std;
vector<int> count_sort(vector<int>&nums)
{
    int shift=50000;
    int max_element=INT_MIN;
    for(int i=0;i<nums.size();i++)
    {
        nums[i]+=shift;

        if(nums[i]>max_element)
        max_element=nums[i];

    }
     
    int freq[max_element+1]={ };

    for(int i=0;i<nums.size();i++)
    {
        freq[nums[i]]++;
    }
    
    vector<int>ans;

    for(int i=0;i<max_element+1;i++)
    {
        if(freq[i]!=0)
        {
            while(freq[i]!=0)
            {
            ans.push_back(i-shift);
            freq[i]--;
            }
        }
    }
    cout << endl;
    return ans;
    
}


int main()
{
    vector<int>s{-5};
   vector<int>ans=count_sort(s);

    for(int i=0;i<ans.size();i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}