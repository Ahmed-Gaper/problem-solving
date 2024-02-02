class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int>mp;
      for(int i=0;i<nums.size();i++)
      {
          mp[nums[i]]++;
      }  
      vector<pair<int,int>>v;
      for(auto x:mp)
      {
       v.push_back({x.second,x.first});
      }
      sort(v.rbegin(),v.rend());
      vector<int>final;
      for(int j=0;j<v.size();j++)
      {
       if(j<k)
       final.push_back(v[j].second);
      }
     return final;
    }
};