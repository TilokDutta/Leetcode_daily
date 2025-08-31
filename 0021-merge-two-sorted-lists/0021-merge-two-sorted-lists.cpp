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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        priority_queue<int,vector<int>, greater<int>> pq;
        while(list1 != nullptr){
            pq.push(list1->val);
            list1 = list1->next;
        }
        while(list2 != nullptr){
            pq.push(list2->val);
            list2 = list2->next;
        }
        ListNode* temp = new ListNode(0);
        ListNode* dummy = temp;
        while(!pq.empty()){
            ListNode* node = new ListNode(pq.top()); pq.pop();
            temp->next = node;
            temp = node;
        }
        return dummy->next;
    }
};