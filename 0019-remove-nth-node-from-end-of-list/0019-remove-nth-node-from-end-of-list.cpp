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
    int noNode = 0;
    int solve(ListNode* head){
        if(head == nullptr){
            return noNode;
        }
        noNode++;
        return solve(head->next);
    }
    int node = 0;
    void del(ListNode* head, int n){
        if(!head || !head->next){
            return;
        }
        node++;
        if(node == noNode - n){
            ListNode* temp = head->next;
            head->next = head->next->next;
            temp->next = nullptr;
            return;
        }
        del(head->next,n);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        solve(head);
        if(n == noNode){
            head = head->next;
            return head;
        }
        del(head,n);
        return head;
    }
};