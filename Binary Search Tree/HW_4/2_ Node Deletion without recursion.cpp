#include<bits/stdc++.h>
using namespace std;
class BinarySearchTree
{
    private :

    int val;
    BinarySearchTree*left;
    BinarySearchTree*right;
    
    public:

    BinarySearchTree(int _val)
    {
        val=_val;
        left=nullptr;
        right=nullptr;
    }

    
	void insert(int target) {
		if (target < val) {
			if (!left) {
				left = new BinarySearchTree(target);
			}
			else
				left->insert(target);
		} else if (target > val) {
			if (!right)
				right = new BinarySearchTree(target);
			else
				right->insert(target);
		} // else: exists already
	}

    BinarySearchTree* max()
    {
        BinarySearchTree *root=this;
        while(root && root->right)
        {
            root=root->right;
        }
        return root;

    }

    void special_delete(BinarySearchTree*chaild)
    {
        val=chaild->val;
        left=chaild->left;
        right=chaild->right;
        delete chaild;

    }

    BinarySearchTree* get_delete2(int target)
    {

        BinarySearchTree*root=this;
        if(!root)
        return nullptr;
        else if(target < val)
        left=left->get_delete2(target);
        else if(target > val)
        right=right->get_delete2(target);
        else
        {
            BinarySearchTree*node=root;
            
            if(!left && !right)
            {
            delete node;
            root=nullptr;
            }
            else if(!left)
            root->special_delete(root->right);
            else if(!right)
            root->special_delete(root->left);
            else
            {
                BinarySearchTree*parent=root;
                BinarySearchTree*chaild=parent->right;
                while(chaild->left)
                {
                    parent=chaild;
                    chaild=chaild->left;
                }

                val=chaild->val;

                if(parent->right==chaild)
                parent->right=chaild->right;
                else
                parent->left=chaild->right;

                delete chaild;

            }
        }


        return root;


    }

    void _get_delete(int target)
    {
        if(!left && !right)
        return;

        get_delete2(target);
        
    }

    void get_inorder()
    {
        BinarySearchTree*root=this;
        if(!root)
        return;

        left->get_inorder();

        cout << val << " ";

        right->get_inorder();
    }


};

int main()
{
    BinarySearchTree tree(10);
    tree.insert(5);
    tree.insert(3);
    tree.insert(8);
    tree.insert(9);
    tree.insert(7);

    tree.get_inorder();
    cout << endl;
    tree.get_delete2(8);
    tree.get_inorder();

    return 0;
}