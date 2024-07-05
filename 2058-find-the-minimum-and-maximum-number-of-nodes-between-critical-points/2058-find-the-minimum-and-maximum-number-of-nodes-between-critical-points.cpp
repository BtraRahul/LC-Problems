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
    //[5,'3',1,2,5,1,2] first=1, nearest = 1 min=INT_MAX, max=0
    //[5,3,1,2,'5',1,2] first=1, nearest= =4 min3, max=3
    //[5,3,1,2,5,'1',2] first=4, nearest= =5 min=1, max=3   {min, max};

    bool isCriticalPoint(int prev, int curr, int nextVal) {
        bool minima = (curr < prev) && (curr < nextVal);
        bool maxima = (curr > prev) && (curr > nextVal);

        return minima || maxima;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, nearest = -1, minVal = INT_MAX, maxVal = 0;

        ListNode* temp = head->next;

        if (!temp || !temp->next)
            return {-1, -1};

        int prev = -1, curr = -1, nextVal = -1;

        prev = head->val;
        curr = temp->val;
        nextVal = temp->next->val;

        int idx = 1;

        while (temp->next) {
            curr = temp->val;
            nextVal = temp->next->val;

            if (isCriticalPoint(prev, curr, nextVal)) {
                if (first == -1) {
                    first = idx, nearest = idx;
                }
                cout << curr << " ";

                if (first != idx) {
                    minVal = min(minVal, idx - nearest);
                    maxVal = max(maxVal, idx - first);
                }
                nearest = idx;
            }

            idx++;
            prev = temp->val;
            temp = temp->next;
        }

        if (minVal == INT_MAX)
            return {-1, -1};

        return {minVal, maxVal};
    }
};