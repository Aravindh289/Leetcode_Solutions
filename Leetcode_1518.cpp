class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        if(numBottles < numExchange) return numBottles;
        int c = 0;
        int empty = 0;
        while(numBottles > 0)
        {
           c+=numBottles;
           numBottles += empty;
           empty = numBottles%numExchange;
           numBottles = (numBottles/numExchange);
        }
        return c;
    }
};