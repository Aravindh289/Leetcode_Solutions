class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int c = 0;
        int empty = 0;
        while(numBottles > 0)
        {
            c+=numBottles;
            empty += numBottles;
            numBottles = 0;
            if(empty >= numExchange)
            {
                empty-=numExchange;
                numBottles+=1;
                numExchange+=1;
            }
            else 
                break;
        }
        return c;
    }
};