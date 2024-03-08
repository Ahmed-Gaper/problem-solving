#include<iostream>
#include<cassert>
using namespace std;
class Dequeue
{
    private :
    int add_elements=0;
    int front=0;
    int rear=0;
    int *arr;
    int size;
    
    public:
    Dequeue(int _size)
    {
        size=_size;
        arr=new int[size];
    }

    int next_back(int pos)
    {
        pos++;
        if(pos==size)
        return 0;
        return pos;
    }

    int next_front(int pos)
    {
        pos--;
        if(pos<0){
        return size-1;
        }
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
        rear=next_back(rear);
        add_elements++;
    }

    void enqueue_front(int val)
    {
        assert(!isfull());
        front=next_front(front);
        arr[front]=val;
        add_elements++;
    }

    void dequeue()
    {
        assert(!empty());
        int val=arr[front];
        front=next_back(front);
        add_elements--;
    }
    void dequeue_back()
    {
        assert(!empty());
        rear=next_front(rear);
        add_elements--;

    }
    void display()
    {
        for(int cur=front;cur!=rear;cur=next_back(cur))
        cout << arr[cur] << " ";
    }


};
int main()
{
    Dequeue q(5);
    q.enqueue_front(3);
    q.enqueue_front(2);
    q.enqueue(4);
    q.enqueue_front(1);
    q.display();
    cout << endl;
    q.dequeue_back();
    q.display();
    cout << endl;
    q.dequeue_back();
    q.dequeue();
    q.dequeue();
    q.display();
    cout << endl;
    
    return 0;
}