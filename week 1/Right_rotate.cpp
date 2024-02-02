#include<iostream>
using namespace std;   


class vector
{
    private :
    int size=0;
    int * ptr=nullptr;

    public :

    vector (int _size)
    {
        if(size<0)
        size=1;

        size=_size;
        ptr=new int[size];

    }

    void set(int idx,int val)

    {
        ptr[idx]=val;
        
    }

    void print ()
    {
        for(int i=0;i<size;i++)
        {
            cout << ptr[i] << " ";
        }
        cout << endl ;
    }

    void right_rotate ()
    {
        int last=ptr[size-1];

        for(int i=size;i>=0;i--)
        {
            ptr[i-1]=ptr[i-2];

        }
        ptr[0]=last;

    }





}; 


int main ()
{

    int size ;
    cout << "the size is : " << endl;
    cin >> size;
    vector first(size);

    cout << "the elements is : " << endl;
    for (int i=0;i<size;i++)
    {
        int val;
        cin >> val;
        first.set(i,val) ;
    } 
  first.right_rotate();
  cout << "After right rotate : " << endl;
  first.print();  

    return 0;
}