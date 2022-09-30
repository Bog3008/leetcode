#include <unordered_map>
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        unordered_map<int, int> m;
        for(int i = 0; i< nums.size(); i++){
            m[nums[i]] += 1;
        }
        for(auto i = m.begin(); i != m.end(); i++)
            if(i->second == 1)
                return i->first;
        return 0;
    }
};
