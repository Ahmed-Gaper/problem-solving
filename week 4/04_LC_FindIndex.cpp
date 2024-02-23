//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/1182459084/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
 public:
     int strStr(string haystack, string needle) {
       int i=0,j=0;
       int fidx=-1;
       while(i<haystack.size() && j<needle.size())
       {
        if(haystack[i]!=needle[j])
        {
            if(fidx!=-1)
            i=fidx+1;
            else
            i++;
            
            fidx =-1;
            j=0;
        
        }
        else 
        { 
            if(j==0)
                fidx=i;

            i++;
            j++;
        }
       }
       if(j==needle.size())
       return fidx;
       else 
       return-1;

     }
 };

int main()
{
    Solution f;
  
    cout << f.strStr("hello","ll");
    return 0;
}

/*فية bugs*/
// class Solution {
// public:
//     int strStr(string haystack, string needle) {
//         int fidx=-1;
//         for(int i=0;i<haystack.size();i++)
//         {
//             if(haystack[i]==needle[0])
//             {
//                 fidx=i;
//                 break;
//             }
    
//         }
//         if(fidx==-1)
//         return -1;

//         int j=0,i=fidx;
//         for(;i<haystack.size()&& j<needle.size();j++,i++)
//         {
//             if(haystack[i]!=needle[j])
//             {
//                 return -1;
//             }
//         }
//         if(j==needle.size())
//         return fidx;
//         else
//         return -1;
        
//     }
// };
