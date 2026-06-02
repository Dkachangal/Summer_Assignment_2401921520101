#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minDayCostTillNow = prices[0];
        int maxFaida = 0;

        for (int i=0; i<prices.size(); i++) {

            minDayCostTillNow = min(prices[i], minDayCostTillNow);
            int currProfit = prices[i] - minDayCostTillNow;
            maxFaida = max(currProfit, maxFaida);
        }
        return maxFaida;
    }
};

int main() {
    Solution solver;
    
    vector<int> prices = {7,1,5,3,6,4};
    
    int maxProfit = solver.maxProfit(prices);
    
    cout << "Max Profit: " << maxProfit << endl; 
    
    return 0;
}