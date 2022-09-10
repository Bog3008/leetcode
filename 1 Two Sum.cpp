class Solution {
public:
    
    
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> answ(2);
        answ[0] = -1;
        vector<int> copy = {nums.begin(), nums.end()};
        sort(nums.begin(), nums.end());
        int L = 0;
        int R = size - 1;
        while(L != R){
            if((nums[L] + nums[R]) > target ){
                --R;
            }
            else{
                if( (nums[L] + nums[R]) == target ){
                    break;
                }
                else{
                    // if((nums[L] + nums[R]) < target )
                    ++L;
                }
            }
        }
        
        for(int i = 0; i < size; ++i){
            if(answ[0] == -1 && copy[i] == nums[L])
                answ[0] = i;
            if(copy[i] == nums[R])
                answ[1] = i;
        }


        return answ;
    }
};
