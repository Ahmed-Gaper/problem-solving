// >>>>>> https://leetcode.com/problems/path-sum/submissions/1306741137/

#include<bits/stdc++.h>
using namespace std;
struct Node_Tree
{
    int val;
    Node_Tree*left=nullptr;
    Node_Tree*right=nullptr;

    Node_Tree(int _val)
    {
        val=_val;
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
        cout << cur->val << " ";
        print_in_order(cur->right);
    }
    
    public :
     Node_Tree*root=nullptr;

    Binary_tree(int _val)
    {
        root=new Node_Tree(_val);
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
                assert(cur->left->val==val[i]);
                cur=cur->left;
            }
            else
            {
                if(!cur->right)
                cur->right=new Node_Tree(val[i]);
                else
                assert(cur->right->val==val[i]);
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

class Solution {
public:
    bool hasPathSum(Node_Tree* root, int targetSum) {

        if(!root)
        return false;

        if(!root->left && !root->right && targetSum==root->val)
        return true;

        if(hasPathSum(root->left,targetSum- root->val) && (hasPathSum(root->right,targetSum- root->val)) )
        {
            return true;
        }
        else 
        return false;



          
      

        
    }
};
int main()
{
    Binary_tree t(5);
    t.add({4,11,7},{'L','L','L'});
    t.add({4,11,2},{'L','L','R'});
    t.add({8,4,1},{'R','R','R'});
    t.add({8,13},{'R','L'});

    Solution s;
    cout << s.hasPathSum(t.root,22);


    
    return 0;
}