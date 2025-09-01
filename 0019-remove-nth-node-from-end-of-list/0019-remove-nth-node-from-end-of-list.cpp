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
    int size = 0;
    void ListSize(ListNode* head){
        while(head){
            head = head->next;
            size++;
        }
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListSize(head);
        if(size == 1 && size == n) return nullptr;
        if(size == n) return head->next;
        int upto = size - n;
        ListNode* cur = head;
        while(cur){
            if(upto == 1){
                ListNode* nextToNext = cur->next->next;
                cur->next->next = nullptr;
                cur->next = nextToNext;
            }
            cur = cur->next;
            upto--;
        }
        return head;
    }
};