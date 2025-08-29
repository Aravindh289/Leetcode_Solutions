class Solution {
public:
    long long flowerGame(int n, int m) {
        long long evenn = 0,oddn = 0;
        long long evenm = 0,oddm = 0;
        for(int i=1;i<=n;i++)
        {
            if(i%2==0) evenn++;
            else oddn++;
        }
        for(int i=1;i<=m;i++)
        {
            if(i%2==0) evenm++;
            else oddm++;
        }
        return oddn*evenm + oddm*evenn;
    }
};