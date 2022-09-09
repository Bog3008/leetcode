class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int row_size = accounts.size();
        int col_size = accounts[0].size();
        int max = -1;
        int boof;
        for(int i = 0; i < row_size; ++i){
            boof = 0;
            for(int j = 0; j < col_size; ++j ){
                boof += accounts[i][j];
            }
            if(boof > max)
                max = boof;
        }
        return max;
    }
};
