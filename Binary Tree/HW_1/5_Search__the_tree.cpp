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

    bool check_is_exists(Node_Tree * cur,int data)
    {
        if(!cur)
        return false;

        if(cur->data==data)
        return true;

        if(check_is_exists(cur->left,data))
        return true;
        else
        {
            if(check_is_exists(cur->right,data))
            return true;
            else 
            return false;
        }



    }


    bool check_is_exists_V2(Node_Tree * cur,int data)
    {
        bool res;
        if(cur->data==data)
        return res=1;
        else 
        res=0;

        if(cur->left)
        res=check_is_exists_V2(cur->left,data);
        if(!res && cur->right)
        res=check_is_exists_V2(cur->right,data);
        
        return res;
        

    }

   
    

    bool is_exists(int _data)
    {
        return check_is_exists_V2(root,_data);
    }

};
int main()
{
    Binary_tree t(1);
    t.add({3},{'L'});
    t.add({13,8},{'R','R'});
    t.add({13,7,10,11},{'R','L','L','L'});

    cout << t.is_exists(11);

    
    return 0;
}