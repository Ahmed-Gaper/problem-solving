// > > > > > > https://leetcode.com/problems/maximum-depth-of-binary-tree/description/


#include<bits/stdc++.h>

struct TreeNode
{ 
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:
    int maxDepth(TreeNode* root) {

        if(!root)
        return 0;

        int l_height=maxDepth(root->left);
        int r_height=maxDepth(root->right);

        if(l_height>=r_height)
        return l_height+1;
        else 
        return r_height+1;


        
    }
};

using namespace std;
int main()
{
    return ;
}