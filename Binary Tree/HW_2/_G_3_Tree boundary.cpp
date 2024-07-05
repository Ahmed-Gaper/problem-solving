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

     void print_in_order(Node_Tree * cur)
    {
        if(!cur)
        return;

        print_in_order(cur->left);
        cout << cur->data << " ";
        print_in_order(cur->right);
    }

    public :
    Node_Tree* root=nullptr;
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

   void tree_left(Node_Tree * cur)
   {

    cout << cur->data << " ";

    if(cur->left)
    tree_left(cur->left);
   else if(cur->right)
    tree_left(cur->right);  /* if there is two if with out else the code will finish the first if and
                             move to the second if */ 
    
   }

    

};
int main()
{

    Binary_Tree t(1);
   t.add( { 2, 4, 7 ,8}, { 'L', 'L', 'R','L' });
	t.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	t.add( { 3, 6, 10 }, { 'R', 'R', 'L' });

    t.tree_left(t.root);

    return 0;
}