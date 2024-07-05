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

    void level_order_traversal(Node_Tree * cur)
    {
        queue<Node_Tree*>q;
        q.push(cur);
        int level=0;
        int size=1;
        
        
        while(!q.empty())
        {
            cout << "Level : " << level << endl;
            size=q.size();
            while(size--)
            {

            cout << q.front()->data << " ";
            
            if(q.front()->left)
            q.push(q.front()->left);

            if(q.front()->right)
            q.push(q.front()->right);

            q.pop();
            }

            cout << endl;


            level++;

        }



    }

};

class Solution {

public:


    bool isCompleteTree(Node_Tree* root) {
        queue<Node_Tree*>q;
        q.push(root);
        int size=1;
         bool check=0;



        
        while(!q.empty())
        {
            size=q.size();
                
            while(size--)
            {
            if(q.front()->left)
            {
                if(check==1)
                return false;
                q.push(q.front()->left);
            }
            else
            check=1;

            if(q.front()->right)
            {
                if(check==1)
                return 0;
            q.push(q.front()->right);
            }
            else
            check=1;;

            q.pop();
            }

            

        }
        return true;
    }
};
int main()
{

    Binary_Tree t(1);
   t.add( { 2, 4 }, { 'L', 'L' });
	t.add( { 2, 5 }, { 'L','R' });
	t.add( { 3, 6}, { 'R',  'L' });

    Solution f;
    cout << f.isCompleteTree(t.root);

     /*           1
            2           3   
        4      5              6 
   7        8     9        10


    */



    return 0;
}