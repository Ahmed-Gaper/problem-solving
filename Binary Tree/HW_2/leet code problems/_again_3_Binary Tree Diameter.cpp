// >>> https://leetcode.com/problems/diameter-of-binary-tree/description/
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

   void clear(Node_Tree * cur) {
		// Don't try to call clear for children and also delete. This deletes twice!
		if (cur->left) {
			delete cur->left;	// recursively delete
			cur->left = nullptr;	// good practice
		}

		if (cur->right) {
			delete cur->right;
			cur->right = nullptr;
		}
	}

    ~Binary_Tree() 
    {
		clear(root);
        root=nullptr;
	}

    

};

class Solution {

public:
    int mx=0;
    int height(Node_Tree * cur)
    {
        if(!cur)
        return 0;

        int l_height=height(cur->left);
        int r_height=height(cur->right);
        if(l_height>=r_height)
        return l_height+1;
        else
        return r_height+1;
    }

    void _diameterOfBinaryTree(Node_Tree* root) {
        if(!root)
        return;

        int lh=height(root->left);
        int rh=height(root->right);

        mx=max(mx,lh+rh);

        _diameterOfBinaryTree(root->left);
        _diameterOfBinaryTree(root->right);
        
    }
    int diameterOfBinaryTree(Node_Tree* root) {
        _diameterOfBinaryTree(root);
        return mx;

        
    }

};
int main()
{

    Binary_Tree t(1);
   t.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	t.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	t.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	t.add( { 3, 6, 10 }, { 'R', 'R', 'L' });
    Solution f;
     f.diameterOfBinaryTree(t.root);
     cout << f.mx;

    /*           1
            2           3   
        4      5              6 
   7        8     9        10


    */


    return 0;
}