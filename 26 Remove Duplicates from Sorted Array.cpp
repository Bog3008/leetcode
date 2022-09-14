// It is two way to solve this
// 1st) More faster but it takes much memory
// 2nd) less memory but slowler
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n_size = 0;
        vector<int> a(nums.size());
        a[n_size] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] != a[n_size]){
                n_size++;
                a[n_size] = nums[i];
            }
        }
        nums = a;
        return ++n_size;
    }
};
