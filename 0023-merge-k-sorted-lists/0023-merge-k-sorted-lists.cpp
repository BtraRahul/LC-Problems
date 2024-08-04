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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto list : lists) {
            ListNode* temp = list;
            while (temp) {
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        cout << pq.size();

        if (pq.size() == 0)
            return NULL;

        ListNode* newNode = new ListNode(pq.top());
        ListNode* head = newNode;
        pq.pop();
        while (pq.size()) {
            newNode->next = new ListNode(pq.top());
            newNode = newNode->next;
            pq.pop();
        }

        return head;
    }
};