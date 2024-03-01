#include<iostream>
#include<cassert>
using namespace std;
class stack
{
    private:
    int*arr=nullptr;
    int size;
    int top1,top2;

    public :
    stack(int _size)
    {
        size=_size;
        arr=new int[size];
        top1=-1;
        top2=size;
    }

    bool isfull()
    {
        if(top1>=top2-1)
        return 1;
        else 
        return 0;
    }

    bool isempty(int id)
    {
        if(id==1)
        return top1==-1;
        return top2==size;
    }

    void push(int id,int val)
    {
        assert(!isfull());
        if(id==1)
        arr[++top1]=val;
        else
        arr[--top2]=val; 
    }

    void pop(int id)
    {
        assert(!isempty(id));

        if(id==1)
        top1--;
        else 
        top2++;
    }

    int peek(int id)
    {
        if(id==1)
        return arr[top1];
        else
        return arr[top2];
    }
     
    
    void display(int id)
    {
        if(id==1)
        {
            for(int i=top1;i>=0;i--)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            for(int i=top2;i<size;i++)
            {
                cout << arr[i] << " ";
            }
        }
    }


};

int main()
{
    stack s(10);
    s.push(1,1);
    s.push(1,2);
    s.push(1,3);
    cout << s.peek(1) << " ";
    s.pop(1);
    cout << s.peek(1) << endl;
    s.push(2,4);
    s.push(2,5);
    s.push(2,6);
    cout << s.peek(2) << " ";
    s.pop(2);
    cout << s.peek(2) << endl;
    s.display(1); cout << endl; s.display(2);

    return 0;
}