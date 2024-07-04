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
    ListNode* mergeNodes(ListNode* head) {
        vector<int> ans;
        int sum=0;

        for(ListNode* temp=head;temp != NULL ;temp=temp->next){
            if(temp->val == 0) {ans.push_back(sum); sum=0;}

            sum+=temp->val; 
        }

        if(sum) ans.push_back(sum);

        head=new ListNode(ans[1]);
        ListNode* temp=head;
        for(int i=2;i<ans.size();i++){
            temp->next=new ListNode(ans[i]);
            temp=temp->next;
        }

        return head;

    }
};