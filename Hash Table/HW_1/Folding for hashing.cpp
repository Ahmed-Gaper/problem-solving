#include<bits/stdc++.h>
using namespace std;
int hash_string(string str,int n)
{
    int new_base=26*2+10;
    long long sum=0;
    long long limit=n;
    for(int i=0;i<str.size();i++)
    {
        int value=0;
        if(str[i]>='A' && str[i]<='Z')
        value = 26+str[i]-'A';

        else if(str[i]>='a' && str[i]<='z')
        value = str[i]-'a';

        else if(isdigit(str[i]))
        value = 26+26+str[i]-'0';

        else
        return false;

        sum = sum*new_base + value;
        sum=sum%limit;

       

    }
    return sum;
}
int folding_hashing(string str,int limit)
{
    long long sum=0;
    int count=0;
    string new_str;

    for(int i=0;i<str.size();i++)
    {

        count++;
        if(count!=5)
        {
            new_str+=str[i];
        }
        else
        {
            i--;
            sum+=hash_string(new_str,limit);
            count=0;
            sum%=limit;
            new_str.clear();
        }

    }

    if(!new_str.empty())
    {

        sum+=hash_string(new_str,limit);
        count=0;
        sum%=limit;
        new_str.clear();
    }
     cout << endl;
    return sum;
}
int main()
{
    cout << folding_hashing("aabcdefgAxT334gfg",65407);
    return 0;
}