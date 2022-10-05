class Solution {
public:
    bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;
    int let_i[26];
    int let_j[26];
    for(char i = 0; i < 26; i++ ){
        let_i[i] = 0;
        let_j[i] = 0;
    }
    for(int i = 0; i < s.size(); i++){
        let_i[s[i] - 97] += 1;
        let_j[t[i] - 97] += 1;
    }
    for(char i = 0; i < 26; i++ ){
        if(let_i[i] !=let_j[i])
            return false;
    }
    return true;
}
};
// Можно еще сортануть но~~~
