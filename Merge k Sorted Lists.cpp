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
        vector<int>ans;
        for(int i=0; i<lists.size(); i++){
            ListNode*curr = lists[i];
            while(curr != NULL){
                ans.push_back(curr->val);
                curr = curr->next;
            }
        }
        sort(ans.begin(), ans.end());
        ListNode*Dummy = new ListNode(-1);
        ListNode*node = Dummy;
        for(int i=0; i<ans.size(); i++){
            ListNode*temp = new ListNode(ans[i]);
            node->next = temp;
            node = temp;
            temp->next = NULL;
        }
        return Dummy->next;

    }
};
