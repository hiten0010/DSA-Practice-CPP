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
    ListNode* rotateRight(ListNode* head, int k) {

        if(head == nullptr || head->next == nullptr || k == 0){
            return head;
        }
        ListNode *tail = head;
        int length = 1;
        while(tail->next != nullptr){
            length++;
            tail = tail->next;
        }

        tail->next = head;

        int steps = length - (k % length);

        while(steps--){
            tail = tail->next;
        }

        head = tail->next;
        tail->next = nullptr;

        return head; 
    }  
};
