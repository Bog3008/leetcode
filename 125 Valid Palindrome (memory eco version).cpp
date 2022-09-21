// this is memory eco code:
class Solution {
public:
    bool isPalindrome(string s) {
    if(s.size() == 0 || s.size() == 1) return true;
    int a = 0;
    int b = s.size() - 1;
    bool flag = 0;
    for(int i  = 0; i < s.size(); i++ ){
        if((65 <= s[i] && s[i] <= 90)){
            s[i] += 32;
        }
    }
    while(true){
        if(!((97 <= s[a] && s[a] <= 122) || (48 <= s[a] && s[a] <= 57))){
            a++;
        }
        if(!((97 <= s[b] && s[b] <= 122) || (48 <= s[b] && s[b] <= 57))){
            b--;
        }
        if (a >= b)
            break;
        if((isalpha(s[a]) && isalpha(s[b])) || (isalnum(s[a]) && isalnum(s[b]))){
            if(s[a] == s[b]){
                a++;
                b--;
            }
            else{
                flag = 1;
                break;
            }
        }
        else if((isalnum(s[a]) && isalpha(s[b])) || (isalnum(s[b]) && isalpha(s[a]))){
                flag = 1;
                break;
            }

    }

    if(flag == 0)
        return true;
    return false;
}
};
