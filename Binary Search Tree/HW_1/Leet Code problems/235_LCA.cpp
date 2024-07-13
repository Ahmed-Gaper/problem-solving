//>>>>https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/submissions/1317579317/
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
class BinarySearchTree
{
    public:
    TreeNode*root=nullptr;
    BinarySearchTree(int _val)
    {
        root=new TreeNode(_val);
    }

    void _insert(TreeNode* root, int target) {
		if (target < root->val) {
			if (!root->left)
				root->left = new TreeNode(target);
			else
				_insert(root->left, target);
		} else if(target > root->val){
			if (!root->right)
				root->right = new TreeNode(target);
			else
				_insert(root->right, target);
		} 
	}

 bool is_BST(TreeNode *root ,int mn=INT_MIN,int mx=INT_MAX){
    bool stat=mn < root->val && root->val < mx;
    
    if(!stat)
    return false;

    bool l_check=!root->left || is_BST(root->left,mn,root->val);
    if(!l_check)
    return false;

    bool r_check=!root->right || is_BST(root->right,root->val,mx);

    return r_check;
    
  
 }

 TreeNode* _search(TreeNode*root,int target)
 {
    if(!root)
    return nullptr;
    
    if(target==root->val)
    return root;
    else if(target < root->val)
    return _search(root->left,target);
    else
    return _search(root->right,target);
 }
};


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
        return nullptr;

        if(p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right,p,q);
        else if(p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left,p,q);
        else
        return root;

        
    }
};
int main()
{
    BinarySearchTree tree(2);
    tree._insert(tree.root,1);
    

    Solution s;
    TreeNode*p=tree._search(tree.root,2);
    TreeNode*q=tree._search(tree.root,1);
    TreeNode*sol=s.lowestCommonAncestor(tree.root,p,q);


    
    
    return 0;
}