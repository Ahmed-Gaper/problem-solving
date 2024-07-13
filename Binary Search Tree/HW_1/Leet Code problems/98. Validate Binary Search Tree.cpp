//>>>>https://leetcode.com/problems/validate-binary-search-tree/description/
#include<bits/stdc++.h>
using namespace std;
struct TreeNode
{
    long long val;
    TreeNode * left=nullptr;
    TreeNode * right=nullptr;
    TreeNode(long long _val)
    {
        val=_val;
    }

};
class BinarySearchTree
{
    public:
    TreeNode*root=nullptr;
    BinarySearchTree(long long _val)
    {
        root=new TreeNode(_val);
    }

    void _insert(TreeNode* root, long long target) {
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

 
};


class Solution {
public:
    bool is_bst(TreeNode*root,long long mn,long long mx)
    {
        bool res= mn<root->val && root->val < mx;

        if(!res)
        return false;
        
        bool l_check=!root->left || is_bst(root->left,mn,root->val);
        bool r_check=!root->right || is_bst(root->right,root->val,mx);

        return l_check && r_check;
        

    }
    bool isValidBST(TreeNode* root) {
        long long mn=LONG_LONG_MIN;
        long long mx=LONG_LONG_MAX;
        return is_bst(root,mn,mx);
        
    }
};
int main()
{
    BinarySearchTree tree(2147483647);
    

    Solution s;
     cout << s.isValidBST(tree.root);
    


    
    
    return 0;
}