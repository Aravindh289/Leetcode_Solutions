class Solution {
public:
    string largestGoodInteger(string num) {
       int n = num.size();
       int maxi = -1;
       for(int i=0;i<=n-2;i++)
       {
            if(num[i] == num[i+1] && num[i] == num[i+2])
            {
                string a = num.substr(i,3);
                int b = stoi(a);
                maxi = max(maxi,b);
            }
       } 
        if(maxi == -1)
          return "";
        if(maxi == 0)
          return "000";
       string rtn = to_string(maxi);  
       return rtn;
    }
};