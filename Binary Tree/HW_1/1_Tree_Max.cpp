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

    int get_Tree_Max(Node_Tree * cur)
    {
        if(!cur)
        return numeric_limits<int>::min(); 
        
        int val=cur->data;
        int L_max=get_Tree_Max(cur->left);
        int R_max=get_Tree_Max(cur->right);

        if(L_max>val)
        val=L_max;

        if(R_max>val)
        val=R_max;

        return val;

    }


    int Tree_Max()
    {
        return get_Tree_Max(root);
    }

};
int main()
{

    Binary_Tree t(1);
   t.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	t.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	t.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	t.add( { 3, 6, 10 }, { 'R', 'R', 'L' });

    t.print();

    cout << t.Tree_Max();

    return 0;
}