#include<bits/stdc++.h>
using namespace std;
int mn=0;
int mx=1000;
bool is_degenerate_tree(vector<int>v)
{
    if(v.size()<=2)
    return true;
    for(int i=1;i<v.size();i++)
    {
        if ( !(v[i]>mn && v[i] < mx) )
        return false;
        
        if(v[i]<v[i-1])
        mx=v[i]+1;
        else if(v[i] >=v[i-1])
        mn=v[i-1]-1;


    }

    return true;


}
int main()
{
    vector<int>v({500,400,600,150,50,20});
    cout << is_degenerate_tree(v);
    return 0;
}