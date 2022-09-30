 #include <unordered_map>
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode *, int> m;
        while(head != nullptr){
            m[head] += 1;
            if(m[head] == 2){
                return true;
            }
            head = head->next;
        }
        return false;
    }
};
