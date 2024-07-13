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
};
int main()
{
    BinarySearchTree tree(10);
    tree._insert(tree.root,5);
    tree._insert(tree.root,3);
    tree._insert(tree.root,7);
    tree._insert(tree.root,15);
    tree._insert(tree.root,12);
    tree._insert(tree.root,20);
    cout << tree.is_BST(tree.root);
    return 0;
}