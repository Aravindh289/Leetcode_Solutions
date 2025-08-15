class Solution {
public:
    int findNthDigit(int n) {
        if(n<=9)
        {
            return n;
        }
        int digisize = 1 , stnum = 1;
        long count = 9;
        while(digisize*count < n)
        {
            n = n - digisize * count;
            digisize++;
            stnum *= 10;
            count *= 10;
        }
        int trgtnum = stnum + (n - 1) / digisize ;
        int trgtidx = (n - 1) % digisize;
        string targetnmbr = to_string(trgtnum);
        return targetnmbr[trgtidx] - '0';
    }
};