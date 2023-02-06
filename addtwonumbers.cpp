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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* actualResult = new ListNode(-1);
        ListNode* result = actualResult;
        int carryOver = 0;
        while (temp1 != NULL && temp2 != NULL) {
            result->next = new ListNode((carryOver + temp1->val + temp2->val)%10);
            
                carryOver = (carryOver + temp1->val + temp2->val)/10;
            
            temp1 = temp1->next;
            temp2 = temp2->next;
            result = result->next;
        }
        while (temp1 != NULL) {
            result->next = new ListNode((carryOver + temp1->val)%10);
          
                carryOver = (carryOver + temp1->val )/10;
        
            temp1 = temp1->next;
            result = result->next;
        }

        while (temp2 != NULL) {
            result->next = new ListNode((carryOver + temp2->val)%10);
            carryOver = (carryOver + temp2->val)/10;
            temp2 = temp2->next;
            result = result->next;
        }
        if (carryOver != 0) {
            result->next = new ListNode(carryOver);
        }
        return actualResult->next;
    }
};
