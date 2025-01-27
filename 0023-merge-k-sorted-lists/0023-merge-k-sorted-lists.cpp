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
        vector<int> v;
        int n  = lists.size();
        for(int i = 0; i < n; i++){
            ListNode* temp = lists[i];
            while(temp != nullptr){
                v.push_back(temp->val);
                temp = temp->next;
            }
        }
        if(v.empty()){
            return nullptr;
        }
        sort(v.begin(),v.end());
        ListNode* temp = new ListNode(v[0]);
        ListNode* head = temp;
        for(int i = 1; i < v.size(); i++){
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }
        return head;
    }
};