class Solution {
public:
string longestCommonPrefix(vector<string>& strs) {
    int size = strs.size();
    string answ = "";
    // check 1st word place than 2nd and ect
    // min ell lengh
    int min_s = strs[0].size();
    for(int i = 1; i < size; i++){
        if(strs[i].size() < min_s)
            min_s = strs[i].size();
    }
    // main check
    bool flag = 0;
    for(int i = 0 ; i < min_s; i++){
        for(int j = 1; j < size; j++){
            if(strs[0][i] != strs[j][i]){
                flag = 1;
                break;
            }
        }
        if(flag != 1){
            answ += strs[0][i];
        }
        else{
            break;
        }
    }
    return answ;
}  
};
