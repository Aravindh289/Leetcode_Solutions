class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        vector<bool> ba(n,false);
        int req = 0;
        for(int i=0;i<n;i++)
        {
            bool isplaced = false;
            for(int j=0;j<n;j++)
            {
                if( !ba[j] && baskets[j] >= fruits[i] )
                {
                    isplaced = true;
                    ba[j]=true;
                    break;
                }
            }   
            if(!isplaced)
            {
                req++;
            }
        }
        return req;
    }
};