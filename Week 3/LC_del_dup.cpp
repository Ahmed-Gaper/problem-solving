/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
    Node *L = head;
    
    while (L && L->next) {
        if (L->data == L->next->data) {
            Node *delptr = L->next;
            L->next = L->next->next;
            if (L->next) {
                L->next->prev = L;
            }
            delete delptr;
        } else {
            L = L->next;
        }
    }
    
    return head;
}

