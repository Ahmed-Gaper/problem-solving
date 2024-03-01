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
    string reverse_word(string line)
    {
        Stack s(line.size());
        line+=' ';
        string Rword;

        for(int i=0;i<line.size();i++)
        {
            if(line[i]==' ')
            {
                while(!s.isempty())
               Rword+= s.pop();
               Rword+=' ';
            }
            else
            s.push(line[i]);
        }
        
        
        return Rword;


    }

    

};
int main()
{
    
    string word;
    getline(cin,word);
    solution f;
    cout << f.reverse_word(word);

    
    return 0;
}