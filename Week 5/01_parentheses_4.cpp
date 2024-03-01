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
    int pop ()
    {
        assert(!isempty());
        return arr[top--];
    }
    int peek()
    {
        return arr[top];
    }
    

};

class solution
{
    public :
    char check(char c)
    {
        if(c==')')
        return '(';
        else if(c==']')
        return '[';
        else if(c=='}')
        return '{';
        else
        return '$';
         
    }
    bool valid_parantheses(string par)
    {
        if(par.empty())
        return true;
       Stack s(par.size());
       for(char c:par)
       {
        if(c=='(' || c=='[' || c=='{')
        s.push(c);
        else if(s.isempty() || s.pop()!=check(c))
        return false;
       }
       if(s.isempty())
       return 1;
       else
       return 0;


    }

    

};
int main()
{
    
    string parentheses;
    cin >> parentheses;
    solution f;
    cout << f.valid_parantheses(parentheses);

    
    return 0;
}