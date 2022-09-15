
class Solution {
public:
    
    vector<int> plusOne(vector<int>& digits) {
        bool stat = 0;
        for(int i = digits.size() - 1; i >= 0; --i){
            if(digits[i] != 9 ){
                digits[i]++;
                stat = 0;
                break;
            }
            else{
                digits[i] = 0;
                stat = 1;
            }
            
        }
        if (stat == 1)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};
