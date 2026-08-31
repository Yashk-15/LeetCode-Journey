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
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenhead = head->next;

        while(even != NULL && even->next != NULL){
            ListNode* nextodd = even->next;
            ListNode* nexteven = even->next->next;

            odd->next = nextodd;
            odd = nextodd;
            
            even->next = nexteven;
            even = nexteven;
        }
        odd->next = evenhead;
        return head;
    }
};