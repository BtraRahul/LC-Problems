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
    ListNode* removeZeroSumSublists(ListNode* head) {

        if (!head)
            return head;
        // Ps "1 3 0" 3 4
        // Ps 1 3 "6 3" 7

        // ListNode* temp = head;

        // vector<ListNode*> nodes;
        // while (temp) {
        //     nodes.push_back(temp);
        //     temp = temp->next;
        // }
        // vector<int> pf(nodes.size());
        // nodes.push_back(NULL);
        // pf[0] = nodes[0]->val;

        // for (int i = 1; i < pf.size(); i++) {
        //     pf[i] = pf[i - 1] + nodes[i]->val;
        // }
        // unordered_map<int, vector<int>> mp;

        // for (int e : pf)
        //     cout << e << " ";
        // cout << endl;

        // int head_start = 0;
        // for (int i = 0; i < pf.size(); i++) {
        //     if (pf[i] == 0) {
        //         head = nodes[i + 1];
        //         mp.clear();
        //     } else {
        //         mp[pf[i]].push_back(i);
        //     }
        // }
        // for (auto ele : mp) {
        //     cout << ele.first << ": ";
        //     for (auto e : ele.second)
        //         cout << e << " ";
        //     cout << endl;
        // }

        // return head;

        unordered_map<int, ListNode*> mp;
        int prefixSum = 0;
        ListNode* temp = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        mp[0] = dummy;

        while (temp) {
            prefixSum += temp->val;
            if (mp.find(prefixSum) != mp.end()) {
                ListNode* start = mp[prefixSum]->next;
                int sum = prefixSum + start->val;
                while (start != temp) {
                    mp.erase(sum);
                    start = start->next;
                    sum += start->val;
                }
                mp[prefixSum]->next = temp->next;
            } else {
                mp[prefixSum] = temp;
            }
            temp = temp->next;
        }

        return dummy->next;
    }
};