//231-power of 2
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) 
           return false;
        while(n%2==0)
        {
            n/=2;
        }
        return n==1;
    }
};
//326 - power of 3
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) 
          return false;
        while(n%3 == 0)
        {
            n/=3;
        }
        return n==1;
    }
};
//power of 4
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0)
           return 0;
        while(n%4==0)
        {
            n/=4;
        }
        return n==1;
    }
};