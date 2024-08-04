/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
   ListNode *merged(ListNode *a, ListNode *b)
    {
        if (a == NULL)
            return b;
        if (b == NULL)
            return a;
        ListNode *newnode = NULL, *head = NULL;
        ListNode *i = a, *j = b;
        while (i != NULL && j != NULL)
        {
            if (i->val < j->val)
            {
                if (newnode == NULL)
                {
                    newnode = i;
                    i = i->next;
                    newnode->next = NULL;
                    head = newnode;
                }
                else
                {
                    newnode->next = i;
                    i = i->next;
                    newnode = newnode->next;
                    newnode->next = NULL;
                }
            }
            else
            {
                if (newnode == NULL)
                {
                    newnode = j;
                    j = j->next;
                    newnode->next = NULL;
                    head = newnode;
                }
                else
                {
                    newnode->next = j;
                    j = j->next;
                    newnode = newnode->next;
                    newnode->next = NULL;
                }
            }
        }
        if (i == NULL)
            newnode->next = j;
        if (j == NULL)
            newnode->next = i;
        return head;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *newnode = NULL;
        for (int i = 0; i < lists.size(); i++)
        {
            newnode = merged(newnode, lists[i]);
        }
        return newnode;
    }
};