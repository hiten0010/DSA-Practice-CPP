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
    class compare{
        public:
        bool operator()(ListNode * a , ListNode * b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue< ListNode * ,vector<ListNode *>, compare > pt;

        for(int i =0 ; i<lists.size() ; i++){
            if(lists[i] != nullptr){
                pt.push(lists[i]);
            }
        }

        ListNode * dummy = new ListNode(-1);
        ListNode * tail = dummy;

        while(!pt.empty()){
            ListNode * temp = pt.top();
            pt.pop();

            if(temp->next != nullptr){
                pt.push(temp->next);
            }

            tail->next = temp;
            tail = tail->next;
        }
        tail->next = nullptr;
        return dummy->next;
    }
};
