//https://leetcode.com/problems/sliding-window-maximum/
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

 struct Mono
{
    queue<int>q;
    deque<int>dq;
    void push(int val)
{
    q.push(val);
    while (!dq.empty() && dq.back() < val)
        dq.pop_back();
    dq.push_back(val);
}


    void pop()
    {
        if(dq.front()==q.front())
        {
            dq.pop_front();
        }
        q.pop();
    }
    int max()
    {
        return dq.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
   
Mono mq;
vector<int>ans;
for(int i=0;i<nums.size();i++)
{
    if(i<k)
    {
    mq.push(nums[i]);
    }
    else
    { 
        ans.push_back(mq.max());
        mq.pop();
        mq.push(nums[i]);

    }


}
ans.push_back(mq.max());
return ans;
    }

        
    
};

int main()
{
    vector<int>q={1,3,1,2,0,5};
    Solution f;
    vector<int>ans;
    ans=f.maxSlidingWindow(q,3);
    for(int i=0;i<ans.size();i++)
    {
        cout << ans.at(i) << " ";
    }

    


    return 0;
}