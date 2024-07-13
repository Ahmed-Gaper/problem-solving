#include<bits/stdc++.h>
using namespace std;

class BinarySearchTree
{
    private :
    int val;
    BinarySearchTree * left;
    BinarySearchTree * right;

    public:

    BinarySearchTree(int _val,BinarySearchTree*_left=nullptr,BinarySearchTree*_right=nullptr)
    {
        val=_val;
        left=_left;
        right=_right;
    }

    void get_in_order()
    {
        if(left)
        left->get_in_order();

        cout << val << " ";
        if(right)
        right->get_in_order();
    }


    void _insert(int target) {
		if (target < val) {
			if (!left)
				left = new BinarySearchTree(target);
			else
				_insert(target);
		} else if(target > val){
			if (!right)
				right = new BinarySearchTree(target);
			else
				_insert(target);
		} 
	}

 bool is_BST(int mn=INT_MIN,int mx=INT_MAX){
    bool stat=mn < val && val < mx;
    
    if(!stat)
    return false;

    bool l_check=!left || is_BST(mn,val);
    if(!l_check)
    return false;

    bool r_check=!right || is_BST(val,mx);

    return r_check;
    
  
 }

 void level_order_traversal2() {
		queue<BinarySearchTree*> nodes_queue;
		nodes_queue.push(this);

		int level = 0;
		while (!nodes_queue.empty()) {
			int sz = nodes_queue.size();

			cout<<"Level "<<level<<": ";
			while(sz--) {
				BinarySearchTree*cur = nodes_queue.front();
				nodes_queue.pop();

				cout << cur->val << " ";
				if (cur->left)
					nodes_queue.push(cur->left);
				if (cur->right)
					nodes_queue.push(cur->right);
			}
			level++;
			cout << "\n";
		}
	}

    int LCA(int x,int y)
    {
        if(val > x && val > y)
        return left->LCA(x,y); 
        else if(val<x && val<y)
        return right->LCA(x,y);

        return val;
    }

};

BinarySearchTree* build_balanced_bst_tree(vector<int> &values,int str=0,int end=-10)
{
    if(end==-10)
    end=values.size()-1;

    if(str > end)
    return nullptr;

    int mid=(str+end)/2;

    BinarySearchTree*_left=build_balanced_bst_tree(values,str,mid-1);
    BinarySearchTree*_right=build_balanced_bst_tree(values,mid+1,end);
    BinarySearchTree *root=new BinarySearchTree(values[mid],_left,_right);
    return root;



}
int main()
{
    vector<int>v({1,2,3,4,5,6});
    BinarySearchTree*BST=build_balanced_bst_tree(v);

    cout << BST->LCA(6,5);


    
   
    return 0;
}