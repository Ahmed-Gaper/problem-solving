#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
class BinaryTree
{
    private :

    char val;
    BinaryTree * left=nullptr;
    BinaryTree * right=nullptr;

    public :

    BinaryTree(int _data)
    {
        val=_data;
    }

    BinaryTree(string postfix)
    {
        stack <BinaryTree*> tree;
        for(int i=0;i<postfix.size();i++)
        {

            BinaryTree *cur=new BinaryTree(postfix[i]);

            if (!isdigit(postfix[i]))
            {
                cur->right=tree.top();
                tree.pop();
                cur->left=tree.top();
                tree.pop();
                

            }
            tree.push(cur);
        }

        BinaryTree * f=tree.top();
        left=f->left;
        right=f->right; 
        val=f->val;      
    }

    void print_inorder()
    {
        if(left)
        {
            if(!(!left->left && !left->right ))
            cout << "(";
        left->print_inorder();
            if(!(!left->left && !left->right ))
            cout << ")";
        }

        cout << val;

        if(right)
        {
            if(!(!right->left && !right->right))
            cout << "(";
        right->print_inorder();
            if(!(!right->left && !right->right))
            cout << ")";
        }
    }


};
int main()
{
    BinaryTree root("51+");
    root.print_inorder();
    cout << endl;
    BinaryTree root2("32*1+");
    root2.print_inorder();
    

    return 0;
}