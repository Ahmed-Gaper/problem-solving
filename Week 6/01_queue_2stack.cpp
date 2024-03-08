#include<iostream>
#include <cassert>
using namespace std;
class Stack
{
    private :
    int* arr=nullptr;
    int size;
    int top=-1;
    int add_elements;

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
        add_elements++;
    }
    int pop ()
    {
        assert(!isempty());
        return arr[top--];
        add_elements++;
    }
    int peek()
    {
        return arr[top];
    }
    int elements()
    {
        return add_elements;
    }

    

};
class queue
{
    private:
        Stack s1;
        Stack s2;

    public:
        queue(int _size) : s1(_size), s2(_size) {
            
        }

        void push(int val)
        {
            int counter=s1.elements();
            while(counter--)
            {
                s2.push(s1.pop());
            }
            counter++;
            s1.push(val);
            while(counter--)
            {
                s1.push(s2.pop());
            }
        }
};
