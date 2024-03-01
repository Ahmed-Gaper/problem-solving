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
    void display()
    {
        for(int i=top;i>=0;i--)
        {
            cout << arr[i] << " ";
        }
    }


void insert_bottom(int x)
{
    if(isempty())
    push(x);
    else
    {
        int cur=arr[top];
        pop();
    
        insert_bottom(x);
        push(cur);

    }
}

///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////

void reverse()
{
    if(isempty())
    return;
    
    int cur=arr[top];
     pop();
     reverse();
     insert_bottom(cur);

}

    

};


int main()
{
    
    Stack s(10);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.display();
    s.reverse();
    cout << endl;
    s.display();

    

    
    return 0;
}