class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int len_row = ransomNote.length(), len_col = magazine.length();
        int mark = 0;
        for(int i = 0; i < len_row; ++i){
            for(int j = 0; j < len_col; ++j){
                if(ransomNote[i] != '\0' && ransomNote[i] == magazine[j]){
                    ransomNote[i] = '\0';
                    magazine[j] = '\0';
                    mark += 1;
                    if (mark == len_row){
                        return true;
                    }
                    break;
                }
            }
        }
        return false;
    }
};
