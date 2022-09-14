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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode * answ = new ListNode;
    ListNode * true_answ = answ;
    ListNode * boof1 = list1;
    ListNode * boof2 = list2;
    while(true){
        if(boof1 != nullptr && boof2 != nullptr) {
            if(boof1->val < boof2->val){
                //add B1
                answ->next = new ListNode;
                answ = answ->next;
                answ->val = boof1->val;
                boof1 = boof1->next;
            }
            else{
                //add B2
                answ->next = new ListNode;
                answ = answ->next;
                answ->val = boof2->val;
                boof2 = boof2->next;
            }
        }
        else{
            if(boof1 == nullptr && boof2 == nullptr){
                break;
            }
            else{
                if(boof1 != nullptr){
                    //add b1
                    answ->next = new ListNode;
                    answ = answ->next;
                    answ->val = boof1->val;
                    boof1 = boof1->next;
                }
                else{
                    //add b2
                    answ->next = new ListNode;
                    answ = answ->next;
                    answ->val = boof2->val;
                    boof2 = boof2->next;
                }
            }
        }
    }
        answ = true_answ;
    true_answ = true_answ->next;
    delete answ;
    return true_answ;
}
};
