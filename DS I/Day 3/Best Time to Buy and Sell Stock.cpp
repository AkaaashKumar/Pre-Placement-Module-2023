class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int min=INT_MAX,profit=0;
        for(int i=0;i<prices.size();i++){
            min=std::min(min,prices[i]);
            profit=std::max(profit,prices[i]-min);
        }
        return profit;
    }
};
