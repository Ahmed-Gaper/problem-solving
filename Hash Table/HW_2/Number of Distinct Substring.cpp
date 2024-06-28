#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin >> str;
    unordered_set<string>s;
    for(int i=0;i<str.size();i++)
    {
        for(int j=i;j<str.size();j++)
        {    
            string sub="";

            for(int k=i;k<=j;k++)
            {
            sub+=str[k];
            s.insert(sub);

            }


        }
    }

    cout << s.size();
    return 0;
}