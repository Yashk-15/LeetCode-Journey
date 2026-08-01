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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL) return head;
        ListNode* odd=head;
        ListNode* evn=head->next;
        ListNode* evnH=evn;
        while(evn != NULL && evn->next != NULL) {
            odd->next = odd->next->next; 
            evn->next = evn->next->next; 
            odd = odd->next;
            evn = evn->next;
        }
        odd->next=evnH; 
        return head;
    }
};