/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map< ListNode * , int> m;
        ListNode * temp = head;
        while(temp != nullptr){
            if(m.find(temp) == m.end()){
                m[temp]++;
            }
            else{
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};
