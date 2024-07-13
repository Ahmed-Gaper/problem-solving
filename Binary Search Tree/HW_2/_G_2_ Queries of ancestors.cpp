#include<bits/stdc++.h>
using namespace std;



class BinarySearchTree
{
    private :
    int val;
    BinarySearchTree*left;
    BinarySearchTree*right;

    public :  
    BinarySearchTree(int _val,BinarySearchTree*_left=nullptr,BinarySearchTree*_right=nullptr)
    {
        val=_val;
        left=_left;
        right=_right;
    }


    void  insert(int _val)
    {
        BinarySearchTree*root=this;

        if(_val < root->val)
        {

        if(root->left)
        root->left->insert(_val);
        else
        root->left=new BinarySearchTree(_val);

        }
        else if(_val > root->val)
        {

        if(root->right)
        root->right->insert(_val);
        else
        root->right=new BinarySearchTree(_val);
        
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

   
  void Queries_of_ancestors(vector<int>&traversal,vector<int>&answers,deque<int>&queries)
  {
    if(queries.empty())
    {
    return;
    }

    if(left && queries.front() < val)
    {

    left->Queries_of_ancestors(traversal,answers,queries);
    
    if(queries.empty())
    {
    return;
    }

    }


    if(!traversal.empty() && queries.front()==traversal.back())
    {
        answers.push_back(val);
        queries.pop_front();

        if(queries.empty())
        {
        return;
        }

    }

    traversal.push_back(val);

    if(right && queries.front() >= val)
    {
        right->Queries_of_ancestors(traversal,answers,queries);
    }
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


	deque<int>queries({15,45,60});
    vector<int>answer;
    vector<int>traversal;

    tree.Queries_of_ancestors(traversal,answer,queries);

    for(int a :answer)
    cout << a << " ";

    return 0;
}