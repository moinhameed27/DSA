// GFG : https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

/*

  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// Way - I (Brute Force [Two Pass])
class Solution
{
public:
    Node *segregate(Node *head)
    {
        Node *mover = head;
        int countZeros = 0, countOnes = 0, countTwos = 0;
        while (mover)
        {
            if (mover->data == 0)
                countZeros++;
            else if (mover->data == 1)
                countOnes++;
            else
                countTwos++;
            mover = mover->next;
        }
        mover = head;
        while (mover)
        {
            if (countZeros)
                mover->data = 0, countZeros--;
            else if (countOnes)
                mover->data = 1, countOnes--;
            else
                mover->data = 2, countTwos--;
            mover = mover->next;
        }
        return head;
    }
};

// Way - II (Optimal [One Pass])
class Solution
{
public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node *segregate(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;
        // Make three separate lists of 0s, 1s, and 2s and at the end link them
        Node *zeroHead = new Node(-1);
        Node *oneHead = new Node(-1);
        Node *twoHead = new Node(-1);
        Node *zero = zeroHead, *one = oneHead, *two = twoHead;
        Node *mover = head;
        while (mover)
        {
            if (mover->data == 0)
            {
                zero->next = mover;
                zero = mover;
            }
            else if (mover->data == 1)
            {
                one->next = mover;
                one = mover;
            }
            else
            {
                two->next = mover;
                two = mover;
            }
            mover = mover->next;
        }
        // If there are one's present, link zero last node next to first element of one and if not present link to two
        zero->next = oneHead->next ? oneHead->next : twoHead->next;
        // One's last node will link to first node of two's
        one->next = twoHead->next;
        // Two's last node will link to nullptr as it will be the last node
        two->next = nullptr;
        Node *newHead = zeroHead->next;
        // Delete all nodes to free up space
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return newHead;
    }
};