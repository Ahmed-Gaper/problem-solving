#include<iostream>
#include<cassert>
using namespace std;
class queue
{
    private :
    int front=0;
    int rear=0;
    int *arr;
    int size;
    
    public:
    queue(int _size)
    {
        size=_size+1;
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

   
    int isFull()
    {
        if(next(rear)==front)
        return 1;
        return 0;
    }
    int isEmpty()
    {
        if(front==rear)
        return 1;
        return 0;
    }

    void enqueue(int val)
    {
        assert(!isFull());
        arr[rear]=val;
        rear=next(rear);
    }

    

   

    int dequeue()
    {
        assert(!isEmpty());
        int val=arr[front];
        front=next(front);
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


int main() {
	queue qu(6);
	assert(qu.isEmpty());
	qu.display();

	for (int i = 1; i <= 6; ++i) {
		assert(!qu.isFull());
		qu.enqueue(i);
		qu.display();
	}
	assert(qu.isFull());

	for (int i = 1; i <= 6; ++i) {
		assert(!qu.isEmpty());
		qu.dequeue();
		//qu.display();
	}

	for (int i = 1; i <= 6; ++i) {
		assert(!qu.isFull());
		qu.enqueue(i);
		qu.display();
	}

	qu.dequeue();
	assert(!qu.isFull());
	qu.enqueue(7);
	assert(qu.isFull());
	qu.display();

	qu.dequeue();
	qu.dequeue();
	assert(!qu.isFull());
	qu.enqueue(8);
	assert(!qu.isFull());
	qu.display();
	qu.enqueue(9);
	assert(qu.isFull());
	qu.display();

	for (int i = 1; i <= 6; ++i) {
		assert(!qu.isEmpty());
		qu.dequeue();
		qu.display();
	}

	return 0;
}


