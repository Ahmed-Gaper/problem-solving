#include<iostream>
using namespace std;

struct node
{
    int data;
    node * next;
    node (int _data)
    {
        data=_data;

    }


};

class linked_list
{
    private :
    node * head=nullptr;
    node * tail=nullptr;
    int length=0;

    public :

    void print ()
    {
        for(node *cur=head;cur;cur=cur->next)
        {
            cout << cur->data << " ";
        }
        cout << endl;
    }

    void insert_end(int val)
    {
        node * new_node=new node(val);
        new_node->next=nullptr;
        if(!head)
        {
            tail=head=new_node;
        }
        else
        {
            tail->next=new_node;
            tail=new_node;
        }
        length++;
    }
        /*///////////////////////////////////////////solution\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
        /*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/    
    int get_ntn_back(int val)
    {
        int counter=length;
        if(val>length)
        return -1;
        for ( node *cur=head;cur;cur=cur->next,counter--)
        {
            if(counter==val)
            return cur->data;
        }
        return -1;
        

    }



   

};


int main()
{
    linked_list list;
    list.insert_end(10);
    list.insert_end(10);
    list.insert_end(55);
    list.insert_end(10);

    list.print();

    int val = list.get_ntn_back(2);
    cout << val;
    

}
