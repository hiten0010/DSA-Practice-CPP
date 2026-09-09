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

        ListNode * empty = new ListNode(0);
        ListNode * curr = empty;
        int carry =0;
        while(l1 != nullptr || l2 != nullptr || carry != 0){
          int sum = 0;

          if(l1 != nullptr){
            sum += l1->val;
            l1 = l1->next;
          }

          if(l2 != nullptr){
            sum += l2->val;
            l2 = l2->next;
          }

          sum += carry;
          curr->next = new ListNode(sum % 10);
          curr = curr->next;
          carry = sum / 10;
        
        }
        ListNode * result = empty->next;
        delete empty;
        return result;
        
    }
};
