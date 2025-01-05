class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;

        int min_price = INT_MAX;
        int maxprofit = 0;

        for(int price:prices){
            min_price = min(min_price,price);
            maxprofit = max(maxprofit,price-min_price);
        }
        return maxprofit;
    }
};