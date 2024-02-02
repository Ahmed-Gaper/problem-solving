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

    void left_rotate ()
    {
        int first=ptr[0];

        for(int i=0;i<size;i++)
        {
            ptr[i]=ptr[i+1];
            

        }
        ptr[size-1]=first;

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
  first.left_rotate();
  cout << "After left rotate : " << endl;
  first.print();  

    return 0;
}