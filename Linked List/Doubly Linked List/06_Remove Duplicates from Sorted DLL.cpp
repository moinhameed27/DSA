// GFG : https://bit.ly/3FtJUtZ

/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
};
*/

// Way - I (Hashing)
/*
Use a map to store data of every node. If data already exits, delete the node.
Time : O(n) , Space : O(n)
*/
class Solution
{
public:
    Node *removeDuplicates(Node *head)
    {
        unordered_map<int, bool> mp;
        Node *mover = head;
        Node *prevNode = nullptr;

        while (mover)
        {
            if (mp[mover->data])
            {
                Node *temp = mover;
                if (prevNode)
                    prevNode->next = mover->next;
                if (mover->next)
                    mover->next->prev = prevNode;
                mover = mover->next;
                delete temp;
            }
            else
            {
                mp[mover->data] = true;
                prevNode = mover;
                mover = mover->next;
            }
        }
        return head;
    }
};

// Way - II (Optimal)
/*
For every Node, check if the next node has the same data. If yes, then delete the next node.
Time : O(n) , Space : O(1)
*/
class Solution
{
public:
    Node *removeDuplicates(struct Node *head)
    {
        Node *mover = head;
        while (mover->next)
        {
            if (mover->data == mover->next->data)
            {
                Node *temp = mover->next;
                mover->next = mover->next->next;
                if (mover->next)
                    mover->next->prev = mover;
                delete temp;
            }
            else
                mover = mover->next;
        }
        return head;
    }
};