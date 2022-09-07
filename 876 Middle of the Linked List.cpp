class Solution {
public:
    ListNode* middleNode(ListNode* head) {
     // хранить ссылку по ходу на ср эл, те обработак за один проход
        ListNode * answ = head;
        int head_ind = 0;
        for(int i = 0; head->next != nullptr; ++i){
            if((i+2)/2 > head_ind){
                head_ind += 1;
                answ = answ->next;
            }
            head = head->next;
        }
        return answ;
    }
};
