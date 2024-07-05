#include<bits/stdc++.h>
using namespace std;
struct Node_Tree
{
    int data;
    Node_Tree*left=nullptr;
    Node_Tree*right=nullptr;

    Node_Tree(int _data)
    {
        data=_data;
    }

};

class Binary_tree
{
    private :
    Node_Tree*root=nullptr;

    void print_in_order(Node_Tree * cur)
    {
        if(!cur)
        return;

        print_in_order(cur->left);
        cout << cur->data << " ";
        print_in_order(cur->right);
    }
    
    public :
    Binary_tree(int _data)
    {
        root=new Node_Tree(_data);
    }


    
    void print()
    {
        print_in_order(root);
        cout << "\n";
    }




     void add(vector<int>val,vector<char>dir)
    {
        assert(val.size()==dir.size());
        Node_Tree *  cur=root;
        for(int i=0;i<val.size();i++)
        {
            if(dir[i]=='L')
            {
                if(!cur->left)
                cur->left=new Node_Tree(val[i]);
                else
                assert(cur->left->data==val[i]);
                cur=cur->left;
            }
            else
            {
                if(!cur->right)
                cur->right=new Node_Tree(val[i]);
                else
                assert(cur->right->data==val[i]);
                cur=cur->right;
            }
        }
    } 

    int get_total_nodes(Node_Tree*cur)
    {
        if(!cur)
        return 0;

        return 1+get_total_nodes(cur->left)+get_total_nodes(cur->right);
    }


    int total_nodes()
    {
        return get_total_nodes(root);
    }

};


int main()
{
    Binary_tree t(1);
    t.add({3},{'L'});
    t.add({13,8},{'R','R'});
    t.add({13,7,10,11},{'R','L','L','L'});

    cout << t.total_nodes();

    
    return 0;
}