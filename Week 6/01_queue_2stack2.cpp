#include<iostream>
#include<cassert>
using namespace std;
class stack
{

    private:

    int *arr;
    int size;
    int top=-1;
    int add_elements;


    public :
    stack(int _size)
    {
        size=_size;
        arr=new int[size];
    }

    bool isfull()
    {
        return top==size-1;
    }

    bool isempty()
    {
        return top==-1;
    }

    void push(int val)
    {
        assert(!isfull());
        arr[++top]=val;
    }
    int pop()
    {
        assert(!isempty());
       
        return arr[top--];
    }

    int peek()
    {
        return arr[top];
    }
    void dis()
    {
        for(int i=top;i>=0;i--)
        {
            cout << arr[i] << " ";
        }
    }


};

class queue
{
    private :

    int size;
    int add_elements=0;
    stack s1;
    stack s2;

    public :

    queue(int _size):s1(_size),s2(_size)
    {
    }


    bool isfull()
    {
        return add_elements==size;
    }

    bool isempty()
    {
        return add_elements==0;
    }

    int dequeue() //O(n)
    {
        while(!s1.isempty())
        s2.push(s1.pop());
         
        int val=s2.pop();

        while(!s2.isempty())
        s1.push(s2.pop());

        add_elements--;
        return val;
    }

    void enqueue(int val) //O(1)
    {
        s1.push(val);
        add_elements++;
    }

  
};


int main()
{
    queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    
    while(!q.isempty())
    cout << q.dequeue() << " ";


    return 0;
}
