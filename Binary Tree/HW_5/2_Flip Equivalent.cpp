//https://leetcode.com/problems/flip-equivalent-binary-trees/description/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode * left=nullptr;
    TreeNode * right=nullptr;

    TreeNode(int _val)
    {
        val=_val;
    }

};

class Binary_Tree
{
    private :

     void print_in_order(TreeNode * cur)
    {
        if(!cur)
        return;
        cout << cur->val << " ";
        print_in_order(cur->left);
        print_in_order(cur->right);
    }

    public :
    TreeNode* root=nullptr;
    Binary_Tree(int _val)
    {
        root=new TreeNode(_val);
    }

   

    void print()
    {
        print_in_order(root);
        cout << "\n";
    }

    void add(vector<int>val,vector<char>dir)
    {
        assert(val.size()==dir.size());
        TreeNode *  cur=root;
        for(int i=0;i<val.size();i++)
        {
            if(dir[i]=='L')
            {
                if(!cur->left)
                cur->left=new TreeNode(val[i]);
                else
                assert(cur->left->val==val[i]);
                cur=cur->left;
            }
            else
            {
                if(!cur->right)
                cur->right=new TreeNode(val[i]);
                else
                assert(cur->right->val==val[i]);
                cur=cur->right;
            }
        }
    }

    string parenthesize_canonical(TreeNode *root)
    {
       

        string res="( " +to_string(root->val);

        vector<string>v;


        if(root->left)
        v.push_back( parenthesize_canonical(root->left) );
        else
        v.push_back("()");

        if(root->right)
        v.push_back( parenthesize_canonical(root->right) );
        else
        v.push_back("()");
      
        sort(v.begin(),v.end());

        for(int i=0;i<v.size();i++)
        {
            res+=v[i]; 
        }

        res+=")";

        return res;


    }

   
};

class Solution {
public:
    string parenthesize_canonical(TreeNode *root)
    {
        if(!root)
        return "";
        string res;
        vector<string>v;
        res+="( "+to_string(root->val);

        if(root->left)
        v.push_back(parenthesize_canonical(root->left));
        else
        v.push_back("()");

        if(root->right)
        v.push_back(parenthesize_canonical(root->right));
        else
        v.push_back("()");

        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
        {
            res+=v[i];
        }
        res+=" )";
        return res;


    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {

        cout << parenthesize_canonical(root1) << "\n";
        cout << parenthesize_canonical(root2) << "\n";

        return parenthesize_canonical(root1)==parenthesize_canonical(root2);
        
    }
};
int main()
{

    Binary_Tree t1(1);
    Binary_Tree t2(1);

    t1.add({2,4},{'L','L'});
    t1.add({2,5,8},{'L','R','R'});
    t1.add({2,5,7},{'L','R','L'});
    t1.add({3,6},{'R','L'});

    t2.add({3,6},{'L','R'});
    t2.add({2,5,7},{'R','R','R'});
    t2.add({2,5,8},{'R','R','L'});
    t2.add({2,4},{'R','L'});

    Solution s;
    cout << s.flipEquiv(t1.root,t2.root);
  


     /*           1
            2           3   
        4      5              6 
   7        8     9        10


    */



    return 0;
}