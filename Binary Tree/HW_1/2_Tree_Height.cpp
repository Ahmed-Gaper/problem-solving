#include<bits/stdc++.h>
using namespace std;
struct Node_Tree
{
    int data;
    Node_Tree * left=nullptr;
    Node_Tree * right=nullptr;

    Node_Tree(int _data)
    {
        data=_data;
    }

};

class Binary_Tree
{
    private :
    Node_Tree* root=nullptr;

     void print_in_order(Node_Tree * cur)
    {
        if(!cur)
        return;

        print_in_order(cur->left);
        cout << cur->data << " ";
        print_in_order(cur->right);
    }

    public :
    Binary_Tree(int _data)
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

    int get_Tree_Height(Node_Tree* cur)
    {
        if(!cur)
        return -1;
        int L_height=get_Tree_Height(cur->left);
        int r_height=get_Tree_Height(cur->right);

        if(L_height>r_height)
        return L_height+=1;
        else
        return r_height+=1;
    }


    int Tree_Height()
    {
        return get_Tree_Height(root);
    }

};
int main()
{

    Binary_Tree t(2);

   
	t.add({3},{'L'});
    t.add({13,8},{'R','R'});
    t.add({13,7,10,11},{'R','L','L','L'});

    t.print();

    cout << t.Tree_Height();

    return 0;
}