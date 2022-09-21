?/ more faster but use more memory
class Solution {
public:
    bool isPalindrome(string s) {
    if(s.size() == 0 || s.size() == 1) return true;
    int a = 0;
    bool flag = 0;
    vector<int> vec(s.size());
    for(int i  = 0; i < s.size(); i++ ){
        if((65 <= s[i] && s[i] <= 90)){
            vec[a] += s[i] + 32;
            a++;
        }
        if((97 <= s[i] && s[i] <= 122)){
            vec[a] = s[i];
            a++;
        }
        if((48 <= s[i] && s[i] <= 57)){
            vec[a] = s[i];
            a++;
        }
    }
    if(a == 0 || a == 1) return true;
    for(int i = 0; i <= a/2; ++i){
        if(vec[i] != vec[a - i - 1]){
            flag = 1;
            break;
        }
    }
    

    if(flag == 0)
        return true;
    return false;
}
};
