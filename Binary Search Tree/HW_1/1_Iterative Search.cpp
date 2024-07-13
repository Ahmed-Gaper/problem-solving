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
class BinaryTree
{
    public:
    TreeNode*root=nullptr;
    BinaryTree(int _val)
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

  bool search_iterative(int target)
  {
    TreeNode*cur=root;
    while(cur)
    {
        if(cur->val==target)
        return true;

        if(cur->val > target )
        cur=cur->left;
        else if(cur->val < target)
        cur=cur->right; 
    }
    return false;
    
  }

};
int main()
{
    BinaryTree tree(10);
    tree._insert(tree.root,5);
    tree._insert(tree.root,3);
    tree._insert(tree.root,7);
    tree._insert(tree.root,15);
    tree._insert(tree.root,12);
    tree._insert(tree.root,20);
    cout << tree.search_iterative(50);
    return 0;
}