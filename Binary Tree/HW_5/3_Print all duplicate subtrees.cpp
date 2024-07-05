//
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
        cout << cur->data << " ";
        print_in_order(cur->left);
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

   
};

class Solution
{
public :

    string parenthesize_canonical(Node_Tree *root,vector<string>&Sub)
    {
       

        string res="(" +to_string(root->data);



        if(root->left)
         res+=parenthesize_canonical(root->left,Sub) ;
        else
        res+="()";

        if(root->right)
        res+= parenthesize_canonical(root->right,Sub) ;
        else
        res+="()";
    
        
        res+=")";

        cout << res << "\n";

if (root->left || root->right)	// nodes > 1
			Sub.push_back(res);
        return res;


    }

void print_all_duplicate_subtree(Node_Tree *root)
{
    vector<string>sub;
    parenthesize_canonical(root,sub);
    cout << endl;

    for(int i=0;i<sub.size();i++)
    cout << sub[i] << " \n";
    cout << endl;



    sort(sub.begin(),sub.end());
     for(int i=0;i<sub.size();i++)
    cout << sub[i] << " \n";
    cout << endl;

    for(int i=0;i<sub.size();)
    {
        int j=i+1;
        while(j<sub.size() && sub[j]==sub[i])
        j++;

        if ( j > (i+1) )
        cout << sub[i] << endl;
        i=j;
    }



}
};
int main()
{

   Binary_Tree tree(1);
	/*
	tree.add( { 2, 4, 8 }, { 'L', 'L', 'L' });
	tree.add( { 2, 4, 9 }, { 'L', 'L', 'R' });
	tree.add( { 2, 5, 10 }, { 'L', 'R', 'L' });
	tree.add( { 2, 5, 11 }, { 'L', 'R', 'R' });

	tree.add( { 3, 6, 12 }, { 'R', 'L', 'L' });
	tree.add( { 3, 6, 13 }, { 'R', 'L', 'R' });
	tree.add( { 3, 7, 14 }, { 'R', 'R', 'L' });
	tree.add( { 3, 7, 15 }, { 'R', 'R', 'R' });
	tree.add( { 3, 7, 15, 16 }, { 'R', 'R', 'R', 'R' });

	Solution().print_duplicate_subtrees(tree.root);
	*/

	tree.add( { 2, 3 }, { 'L', 'L'});
	tree.add( { 4, 5, 6, 8, 9 }, { 'R', 'R', 'R', 'R', 'R' });
	tree.add( { 4, 2, 3 }, { 'R', 'L', 'L'});
	tree.add( { 4, 5, 6, 7 }, { 'R', 'R', 'L', 'L'});
	tree.add( { 4, 5, 6, 8, 9 }, { 'R', 'R', 'L', 'R', 'R'});
	tree.add( { 4, 5, 6, 7 }, { 'R', 'R', 'R', 'L'});

	// (2(3()())())
	// (6(7()())(8()(9()())))
	// (8()(9()()))

    Solution s;
      s.print_all_duplicate_subtree(tree.root);


  
 

     /*           1
            2           3   
        4      5              6 
   7        8     9        10


    */



    return 0;
}