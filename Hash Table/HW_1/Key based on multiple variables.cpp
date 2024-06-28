#include<bits/stdc++.h>
using namespace std;
int hash_num(int num,int limit)
{
    long long n=limit;
    return (num%n + n) %n;
}
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
struct object
{
    const int static limit=2222222;
    string str1,str2;
    int num;

    int hash_code()
    {
        long long code=hash_string(str1+str2,limit);
        code+=hash_num(num,limit);
        return code;
        
    }

    object(string _str1,string _str2,int _num )
    {
        str1=_str1;
        str2=_str2;
        num=_num;
    }


};
int main()
{
    object f("abd","asd",10100);
    cout << f.hash_code();

    return 0;
}