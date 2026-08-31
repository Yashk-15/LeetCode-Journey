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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans = {-1, -1};

        if (head == nullptr || 
            head->next == nullptr || 
            head->next->next == nullptr) {
            return ans;
        }

        ListNode* prev = head;
        ListNode* curr = head->next;

        int position = 1;

        int first = -1;
        int last = -1;
        int minDist = INT_MAX;

        while (curr->next != nullptr) {

            ListNode* next = curr->next;
            bool localMax = curr->val > prev->val &&
                            curr->val > next->val;

            bool localMin = curr->val < prev->val &&
                            curr->val < next->val;

            if (localMax || localMin) {
                if (first == -1) {
                    first = position;
                }
                else {
                    minDist = min(minDist, position - last);
                }
                last = position;
            }
            prev = curr;
            curr = next;
            position++;
        }
        if (first == last) {
            return ans;
        }
        ans[0] = minDist;
        ans[1] = last - first;

        return ans;
    }
};