//два буферных массива которые хранят самую выгодную цену покупки и продажи на данный момент
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0 || prices.size() == 1) return 0;
        int answ = 0;
        int * min = new int [prices.size()];
        int * max = new int [prices.size()];
        min[0] = prices[0];
        max[prices.size() - 1] = prices[prices.size() - 1];
        for(int i = 1; i < prices.size(); ++i ){
            if(min[i - 1] < prices[i])
                min[i] = min[i - 1];
            else
                min[i] = prices[i];

            if(max[prices.size() - i] > prices[prices.size() - i - 1] )
                max[prices.size() - i - 1] = max[prices.size() - i];
            else
                max[prices.size() - i - 1] = prices[prices.size() - i - 1];
        }
        for(int i = 1; i < prices.size(); i++){
            //cout << min[i - 1] << " "<<max[i]<<endl;
            if(max[i] - min[i - 1] > answ)
                answ = max[i] - min[i - 1];
        }

        delete[]  min;
        delete[]  max;
        return answ;
    }
};
