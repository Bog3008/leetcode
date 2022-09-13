#include <stack>
class Solution {
public:
    bool isValid(string s) {
        stack <char> sk;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                sk.push(s[i]);
            }
            else{
                if(!sk.empty() && ((sk.top() == '(' && s[i] == ')') || (sk.top() == '[' && s[i] == ']') || (sk.top() == '{' && s[i] == '}') ) ){
                    sk.pop();
                }
                else{
                    return false;
                }
            }
        }
        return sk.empty();
    }
};
