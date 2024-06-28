#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str1,str2;
    cin >> str1 >> str2;
    unordered_set<string>s1;
    for(int i=0;i<str1.size();i++)
    {
        for(int j=i;j<str1.size();j++)
        {    
            string sub="";

            for(int k=i;k<=j;k++)
            {
            sub+=str1[k];
            s1.insert(sub);

            }


        }
    }

    unordered_set<string>s2;
    for(int i=0;i<str2.size();i++)
    {
        for(int j=i;j<str2.size();j++)
        {    
            string sub="";

            for(int k=i;k<=j;k++)
            {
            sub+=str2[k];
            s2.insert(sub);

            }


        }
    }
    int count=0;


    for(string x:s1)
    {
        if(s2.count(x))
        count++;

    }
    cout << count;

    return 0;
}