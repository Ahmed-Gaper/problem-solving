struct node
{
    string str;
    node * next=NULL;
    node * prv=NULL;
    node(string _str){
        str=_str;

    }

};

class BrowserHistory {

public:
    node * cur=NULL;
    BrowserHistory(string homepage) {
      cur =new node(homepage);         
    }
    
    void visit(string url) {
        node * new_node=new node(url);
        cur->next=new_node;
        new_node->prv=cur;
        cur=new_node;
    }
    
    string back(int steps) {
        while(cur->prv && steps--)
        {
            cur=cur->prv;
        }
        return cur->str;
    }
    
    string forward(int steps) {
         while(cur->next && steps--)
        {
            cur=cur->next;
        }
        return cur->str;
        
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */