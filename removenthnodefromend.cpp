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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == NULL )
            return NULL;
        ListNode *p = head;
        ListNode *count = head;
        
        int length=0;
        while(count){
            length+=1;
            count=count->next;
        }
        if(length-n == 0)
            return head->next;
        else
            for(int i = 1; i<(length-n);i++)
                p=p->next;
        p->next = p->next->next;
        return head;
    }
};
