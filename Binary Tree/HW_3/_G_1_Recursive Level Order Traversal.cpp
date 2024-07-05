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

    void print(Node_Tree * cur,int level)
    {
        if(level==0)
        cout << cur->data << " ";
        else 
        {
              if(cur->right)
            print(cur->right,level -1);
            
            if(cur->left)
            print(cur->left,level -1);

          
        }

    }

    void print_level(Node_Tree * cur,int level=0)
    {
        int h=get_Tree_Height(root);
        for(int i=0;i<=h;i++)
        {
            cout << "Level : " << i << endl;
            print(root,i);
            cout << endl;
            
        }
        

    }


};
int main()
{

    Binary_Tree t(1);
   t.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	t.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	t.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	t.add( { 3, 6, 10 }, { 'R', 'R', 'L' });

    t.print_level(t.root);


    return 0;
}