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

    void print_v2()
    {
        stack< pair<Node_Tree*,bool> > nodes;

        nodes.push({root,0});

        while(!nodes.empty())
        {
            Node_Tree *f=nodes.top().first;
            bool is_done=nodes.top().second;
            nodes.pop();

            if(is_done)
            cout << f->data << " ";
            else
            {
                if(f->left)
                nodes.push({f->left,0});

                nodes.push({f,1});

                if(f->right)
                nodes.push({f->right,0});

            }
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

    t.print();
    cout << endl;
    t.print_v2();

    return 0;
}