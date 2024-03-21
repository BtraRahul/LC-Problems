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
    ListNode* reverseList(ListNode* head) {
        // recursive
        // if (head == NULL || head->next == NULL) { // Base case
        //     return head;
        // }
        // ListNode* smallAns = reverseList(head->next);
        // ListNode* temp = smallAns;
        // while (temp->next != NULL) {
        //     temp = temp->next;
        // }
        // temp->next = head;
        // head->next = NULL;
        // return smallAns;

        if (head == NULL)
            return head;
        ListNode *prev, *curr, *front;
        prev = NULL;
        curr = head;

        while (curr) {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        head = prev;
        return head;
    }
};