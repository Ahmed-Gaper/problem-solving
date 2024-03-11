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

int addelements()
{
    return add_elements;
}

};
class sum_last_k
{
    private :
    int sum=0;
    int k;
    queue q;

    public :
    sum_last_k(int _k):q(_k)
    {  
        k=_k;
    }

    int next(int new_num)
    {
        sum+=new_num;
        if(q.addelements()==k){
            int deq=q.dequeue();
            sum-=deq;
        }
        q.enqueue(new_num);
        return sum;
     


        
    }
    

};


int main()
{
    sum_last_k process(4);
    int num;
    while(cin >> num)
    {
        cout << process.next(num) << endl;
    }
}
