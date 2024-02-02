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

    int search(int val)
    {
        for(int i=0;i<size;i++)
        {
            if(ptr[i]==val)
            {
                swap(ptr[i],ptr[i-1]);
                return i-1;
            }
        }
        return 0;
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

    int value;
    cout << "Enter the value : ";
    cin >> value;
    cout << "return : " << first.search(value) <<endl;
    first.print();

  

    return 0;
}