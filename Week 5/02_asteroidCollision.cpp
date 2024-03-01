#include<iostream>
#include<vector>
#include <cassert>
using namespace std;
class Stack
{
    private :
    int* arr=nullptr;
    int top=-1;

    public :
    int size;

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

void asteroidCollision(int arr[], int len) {
    Stack s(len);
        
        for(int i=0; i<len; i++)
        {
            if (s.isempty() || s.peek() < 0 || (s.peek() > 0 && arr[i] > 0))
            {
                s.push(arr[i]);
            }
            else
            {
                while (!s.isempty() && s.peek() < abs(arr[i]))
                {
                    s.pop();
                }
                if (!s.isempty() && s.peek() == abs(arr[i]))
                {
                    s.pop();
                }
                else if (s.isempty() || s.peek() < 0)
                {
                    s.push(arr[i]);
                }
            }
        }
        if(!s.isempty())
        {
            vector<int> ans(s.size);
            int i = s.size - 1;
            while (!s.isempty())
            {
                ans[i] = s.peek();
                i--;
                s.pop();
            }  
            for(int val: ans) {
                cout << val << " ";
            }
            cout << endl;
        }
}


int main()
{
    
    int arr[4]={-2,2,8,-3};
	asteroidCollision(arr, 3);
    
    return 0;
}