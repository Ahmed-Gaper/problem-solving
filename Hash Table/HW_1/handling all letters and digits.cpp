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
        value = 26+26+str[i];

        else
        return false;

        sum = sum*new_base + value;

    }
    sum=sum%limit;
    return sum;
}
int main()
{
    cout << hash_string("abcAD56",10) << endl;
    cout << hash_string("56abcAD",10) << endl;
    return 0;
}