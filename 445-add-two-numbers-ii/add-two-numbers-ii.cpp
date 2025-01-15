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
    
    ListNode* ReverseLL(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* last = ReverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = ReverseLL(l1); 
        l2 = ReverseLL(l2); 

        int carry = 0;
        ListNode* ans = nullptr;
        
        while (l1 != NULL || l2 != NULL || carry) {
            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            ListNode* newNode = new ListNode(sum % 10);
            carry = sum / 10;

            newNode->next = ans;
            ans = newNode;
        }

        return ans;
    }
};