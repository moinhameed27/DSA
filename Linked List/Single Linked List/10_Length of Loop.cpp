// GFG : https://bit.ly/3dyXL6m

/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// Way - I (Brute Force [Map])
int countNodesinLoop(struct Node *head)
{
    int count = 0;
    // Map to store the Node and it's place
    unordered_map<Node *, int> mp;
    Node *temp = head;
    while (temp)
    {
        count++;
        // If node is founc again, means it's the first node of cycle
        if (mp.find(temp) != mp.end())
            return count - mp[temp];
        mp[temp] = count;
        temp = temp->next;
    }
    // If there is no cycle, return 0
    return 0;
}

// Way - II (Two Pointers)
int countNodesinLoop(struct Node *head)
{
    Node *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        // If there's a cycle, keep slow at the meeting point
        if (slow == fast)
        {
            int count = 1;
            fast = fast->next;
            // Keep moving the fast one step until it meets slow
            while (slow != fast)
            {
                fast = fast->next;
                count++;
            }
            // The length of cycle will be counted as the meeting point will come again after some n count
            return count;
        }
    }
    // If there's no cycle
    return 0;
}

/*
-----------------------------------------------------------------------------------------------------------------
Node = {3, 0, 2, 4}, 4 is connected to 0
Two Pointers:
1. Slow and Fast pointers, Fast moves two steps and Slow moves one step, If there is a cycle, they will meet at some point.
2. Keep slow at the meeting point and move fast one step, count the number of nodes until they meet again

slow = 3, head = 3
slow = 0, fast = 2
slow = 2, fast = 0
slow = 4, fast = 4 (meet)
* Length of Cycle (Keep slow at meeting point)
slow = 4, fast = 4 --> count = 0
slow = 4, fast = 0 --> count = 1
slow = 4, fast = 2 --> count = 2
slow = 4, fast = 4 --> count = 3 (meet again)
*/