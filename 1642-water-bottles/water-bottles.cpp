class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans= (numBottles*numExchange-1)/(numExchange-1);
        return ans;
    }
};