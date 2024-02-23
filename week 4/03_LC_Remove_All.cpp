//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/submissions/1182372705/
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<stack>
#include<string>
using namespace std;
/*// class Solution {
// public:
//     string removeDuplicates(string s) {
//         stack<char>st;
//         for(char c:s)
//         {
//             if(st.empty())
//             st.push(c);
//             else if(!st.empty() && st.top()==c)
//             st.pop();
//             else if(!st.empty() && st.top()!=c)
//             st.push(c);
//         }
//         string ans;
//         int c=st.size();

//         for(int i=c-1;i>=0;i--)
//         {
//             ans.push_back(st.top());
//             st.pop();
        
//         }
//         for(int i=0,j=c-1;;i++,j--)
//         {
//             swap(ans[i],ans[j]);

//         }
//         cout << ans;
//         return ans;

        
//     }
// };*/
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(char c:s)
        {
           
             if(!st.empty() && st.top()==c)
            st.pop();
            else 
            st.push(c);
        }
        string ans="";

       while(!st.empty())
       {
        ans=st.top()+ans; 
        st.pop();
       }
        cout << ans;
        return ans;

        
    }
};
       
int main()
{
    Solution f;
  string ans= f.removeDuplicates("abbaca");
      
    return 0;
}
