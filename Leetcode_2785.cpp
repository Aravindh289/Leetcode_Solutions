class Solution {
public:
    string sortVowels(string s) 
    {
       string vwl;
       for(auto x:s)
       {
          if(x == 'a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='A' || x =='E' || x=='I'
           || x=='O' || x=='U')
           {
               vwl+=x;
           }
       }  
       if(vwl.size()==0)  return s;
       sort(vwl.begin(),vwl.end());
       int st = 0;
       for(int i=0;i<s.size();i++)
       {
         if(s[i] == 'a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || 
         s[i] =='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                s[i] = vwl[st];
                st++;
            }
       }
       return s;
    }
};