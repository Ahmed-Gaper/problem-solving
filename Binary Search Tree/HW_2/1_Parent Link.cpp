#include<bits/stdc++.h>
using namespace std;



class BinarySearchTree
{
    private :
    int val;
    BinarySearchTree*left;
    BinarySearchTree*right;
    BinarySearchTree*parent;

    public :  
    BinarySearchTree(int _val,BinarySearchTree*_parent=nullptr,BinarySearchTree*_left=nullptr,BinarySearchTree*_right=nullptr)
    {
        val=_val;
        left=_left;
        right=_right;
        parent=_parent;
    }


    void  insert(int _val)
    {
        BinarySearchTree*root=this;

        if(_val < root->val)
        {

        if(root->left)
        root->left->insert(_val);
        else
        root->left=new BinarySearchTree(_val,root);

        }
        else if(_val > root->val)
        {

        if(root->right)
        root->right->insert(_val);
        else
        root->right=new BinarySearchTree(_val,root);
        
        }


    }

    BinarySearchTree* _search(int target)
    {
        BinarySearchTree*root=this;

        if(!root)
        return nullptr;
        
        if(root->val==target)
        return root;

        if(target < root->val)
        return root->left->_search(target);
        else if(target > root->val)
        return root->right->_search(target);

        return nullptr;

    }

   
   int min_value()
   {
    BinarySearchTree*root=this;
    if(!root)
    return -1;
     while(root->left)
     {
        root=root->left;
     }
     return root->val;
   }

  pair<bool,int>successor(int target)
  {
    BinarySearchTree*chaild=_search(target);

    if( !chaild )
    return make_pair(false,-1);

    if(chaild->right)
    return make_pair(true,chaild->right->min_value());

    BinarySearchTree*parent=chaild->parent;

    while(parent && parent->right==chaild)
    {
        chaild=parent;
        parent=parent->parent;
    }

    if(parent)
    return make_pair(true,parent->val);

    return make_pair(false,-1);
  }
  
 

};
int main()
{
BinarySearchTree tree(50);
	tree.insert(20);
	tree.insert(45);
	tree.insert(70);
	tree.insert(73);
	tree.insert(35);
	tree.insert(15);
	tree.insert(60);


	vector<int> v { 15, 20, 35, 45, 50, 60, 70, 73, 100 };

	for (int i = 0; i < (int)v.size(); ++i) {
		cout << v[i] << " ";
		pair<bool, int> p = tree.successor(v[i]);

		if (p.first)
			cout << p.second << "\n";
		else
			cout << "NA\n";

	}



    return 0;
}