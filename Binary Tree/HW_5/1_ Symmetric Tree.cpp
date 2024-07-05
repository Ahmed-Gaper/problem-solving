// >>> https://leetcode.com/problems/symmetric-tree/description/

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


   
};
/*   my solution
class Solution {
public:
  bool isSymmetric(TreeNode * root)
    {
        if(!root->left && !root->right)
        return 1;

        TreeNode * null=new TreeNode(0x3f3f3f3f);

        queue<TreeNode*>q;
        deque<TreeNode*>dq;
        q.push(root);
        int level=0;
        int size=1;
        
        
        while(!q.empty())
        {
            size=q.size();
            while(size--)
            {

            if(q.front()->left)
            {
            q.push(q.front()->left);
            dq.push_back(q.front()->left);
            }
            else
            dq.push_back(null);

            if(q.front()->right)
            {
            q.push(q.front()->right);
            dq.push_back(q.front()->right);
            }
            else
            dq.push_back(null);

            q.pop();
            }

            while(!dq.empty())
            {
                if(dq.front()->val!=dq.back()->val)
                {
                return 0;
                }
                dq.pop_back();
                dq.pop_front();
            }
        }

        return 1;



    }
};*/
/*v_2
class Solution {
public:
bool check(TreeNode *first,TreeNode * second)
{
    if(!first && !second)
    return true;

    if(first && !second || !first && second || first->val !=second->val)
    return false;

    return check(first->left,second->right) && check(first->right , second->left);


}
    bool isSymmetric(TreeNode* root) {
        if(!root)
        return true;
        return check(root->left , root->right);
        
    }
};*/
class Solution {
public:


    string parenthesize(TreeNode *root)
    {
       

        string res="( " +to_string(root->val);

        if(root->left)
        res+=parenthesize(root->left);
        else
        res+= "()";

        if(root->right)
        res+=parenthesize(root->right);
        else
        res+= "()";
        res+=" )";

        return res;


    }
    bool isSymmetric(TreeNode* root) {

        
    }
};
int main()
{

    Binary_Tree t(1);
    t.add({2},{'R'});
    t.add({2},{'L'});

    Solution s;
  

   cout <<  s.isSymmetric(t.root);

     /*           1
            2           3   
        4      5              6 
   7        8     9        10


    */



    return 0;
}