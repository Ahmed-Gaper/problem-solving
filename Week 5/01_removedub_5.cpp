#include<iostream>
#include <cassert>
using namespace std;
class Stack
{
    private :
    int* arr=nullptr;
    int size;
    int top=-1;

    public :
    Stack(int val )
    {
        size=val;
        arr=new int[size];
    }
    int isfull()
    {
        if(top==size-1)
        return 1;
        else
        return 0;
    }
    int isempty()
    {
        if(top==-1)
        return 1;
        else
        return 0;

    }

    void push (int val)
    {
        assert(!isfull());
        arr[++top]=val;
    }
    void pop ()
    {
        assert(!isempty());
         top--;
    }
    char peek()
    {
        return arr[top];
    }
    

};

class solution
{
    public :
    string remove_ad_dub(string word)
    {
        Stack s(word.size());
        for (char c:word)
        {
            if(!s.isempty() && s.peek()==c)
            s.pop();
            else
            s.push(c);
        }

        string ans="";
        int i=0;
        while(!s.isempty())
        {
            ans=s.peek()+ans; // عشان تتعرض مترتبة
            s.pop();
            i++;
        }
        return ans;
       
        


    }

    

};
int main()
{
    
    string word;
    cin >> word;
    solution f;
    cout << f.remove_ad_dub(word);

    
    return 0;
}