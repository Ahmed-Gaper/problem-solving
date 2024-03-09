#include<iostream>
#include<cassert>

using namespace std;

struct task
{
    int id;
    int P;

    task(int _id,int _p)
    {
        id=_id;
        P=_p;
    }
    task()
    {

    }

};

class queue
{
    private :
    task *arr;
    int size;
    int add_elements=0;
    int front=0,rear=0;
    
    public :
    queue(int _size)
    {
        size=_size;
        arr=new task[size];

    }
    
    bool isfull()
    {
        return add_elements==size;
    }

    bool isempty()
    {
        return add_elements==0;
    }

    int next(int pos)
    {
        ++pos;
        if(pos==size)
        return 0;

        return pos;
    }

    void enqueue(task val)
    {
        assert(!isfull());
        add_elements++;
        arr[rear]=val;
        rear=next(rear);
        

    }

    task dequeue()
    {
        assert(!isempty());
        add_elements--;

        task val=arr[front];
        front=next(front);
        return val;

    }

};

class priority_queue
{
    private :
    queue q1,q2,q3;

    public :
    priority_queue(int _size):q1(_size),q2(_size),q3(_size)
    {}

    void push(task t)
    {
        if(t.P==3)
        q3.enqueue(t);
        else if(t.P==2)
        q2.enqueue(t);
        else if(t.P==1)
        q1.enqueue(t);
    }
    
    int dequeue()
    {
        if(!q3.isempty())
        return q3.dequeue().id;
        else if(!q2.isempty())
        return q2.dequeue().id;
        else
        return q1.dequeue().id;
    }



};
int main() 
{
    task t2(2222,2);
    task t3(333,3);
    task t1(111,1);
    task t4(111,1);

    priority_queue q(4);
    q.push(t2);
    q.push(t3);
    q.push(t1);
    q.push(t4);

    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";

  
    return 0;
}
