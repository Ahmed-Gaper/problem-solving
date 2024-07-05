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

    void print_in_order(Node_Tree * cur)
    {
        if(!cur)
        return;

        print_in_order(cur->left);
        cout << cur->data << " ";
        print_in_order(cur->right);
    }
    
    public :
    Node_Tree*root=nullptr;

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


    bool is_perfect(Node_Tree * cur)
    {
        bool res=0;

        if(!cur->left && !cur->right)
        res=1;
        

      if(res==0)
      {
        if(cur->left && cur->right)
        {
            return is_perfect(cur->left) && is_perfect(cur->right);

        }
        else
        return 0;
      }
      return 1;
    }


    bool is_perfect_formula()
    {
        int h=tree_height(root);
        int n=count_all_nodes(root);

        if( (pow(2,h+1)-1) == n)
        return true;
        else
        return false;
    }


};
int main()
{
    Binary_tree t(1);
    t.add({3},{'L'});
    t.add({13},{'R'});
  

    cout << t.is_perfect(t.root);


    
    return 0;
}