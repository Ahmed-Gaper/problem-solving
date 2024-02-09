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
    }


        /*///////////////////////////////////////////solution\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
        /*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv*/

    ~linked_list()
    {
        int num=0;
        node * after;
        for(node * cur=head;cur;)
        {
            after=cur->next;

            delete cur;
            cur=nullptr;
            cout << "delete " << ++num << " ";
            cur=after;
        }

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
    

}