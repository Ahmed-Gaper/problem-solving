#include<iostream>
#include<cassert>
using namespace std;
class queue
{
    private :
    int add_elements=0;
    int front=0;
    int rear=0;
    int *arr;
    int size;
    
    public:
    queue(int _size)
    {
        size=_size;
        arr=new int[size];
    }

    int next(int pos)
    {
        pos++;
        if(pos==size)
        return 0;
        return pos;
    }

    int Next_front(int pos)
    {
        pos--;
        if(pos<0)
        return size-1;
        return pos;
    }

   
    int isfull()
    {
        return add_elements==size;
    }
    int empty()
    {
    return add_elements==0;
    }

    void enqueue(int val)
    {
        assert(!isfull());
        arr[rear]=val;
        rear=next(rear);
        add_elements++;
    }

    void insert_front(int val)
    {
        int counter=add_elements;
        enqueue(val);
        while (counter--)
        {
            enqueue(dequeue());
        }
        

    }

   

    int dequeue()
    {
        assert(!empty());
        int val=arr[front];
        front=next(front);
        add_elements--;
        return val;
    }
    
    void display()
    {
        for(int cur=front;cur!=rear;cur=next(cur))
        cout << arr[cur] << " ";
    }

    int peek()
{
    return arr[front];
}



};

class stack
{
    private:
    queue q;

    public:
    stack(int size) : q(size)
    {
    }

    void push(int val)
    {
        q.insert_front(val);

    }

    void pop()
    {
        int val =q.dequeue();
    }
    int top()
    {
        return q.peek();
    }

    void dis()
    {
        while(!q.empty())
        {
            cout << q.peek() << " ";
            int val=q.dequeue();
        }
    }
    
    


};
int main()
{
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.dis();
    return 0;


}