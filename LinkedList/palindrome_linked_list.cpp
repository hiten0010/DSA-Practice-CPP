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
    ListNode * findmid(ListNode * head){
        ListNode * fast = head;
        ListNode * slow = head;
        
        while(fast->next != nullptr){
            fast = fast->next;

            if(fast->next != nullptr){
                fast =fast->next;
                slow = slow->next;
            }
        }
        return slow;
        }
    ListNode * reverse(ListNode * head2){
        ListNode * prev = nullptr;
        ListNode * curr = head2;
        
        while(curr != nullptr){
           ListNode * temp = curr->next;
           curr->next = prev;
           prev = curr;
           curr = temp;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        ListNode * mid = findmid(head);
        ListNode * head2 = mid->next;
        mid->next = nullptr;
        ListNode * newhead1 = head;
        ListNode * newhead2 = reverse(head2);
        while(newhead2 != nullptr){
            if(newhead1->val != newhead2->val){
                return false;
            }
            newhead1 = newhead1->next;
            newhead2 = newhead2->next;
        }
        return true;
    }
};
