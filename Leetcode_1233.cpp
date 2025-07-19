//brute force approach
class Solution {
public:
    bool isSubfolder(string a,string b)
    {
        int i=0;
        for(i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])
            {
                return false;
            }
        }
        return b[i]=='/'?true:false;
    }
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        int n = folder.size();
        vector<string> rslt;
        for(int i=0;i<n;i+=1)
        {
            for(int j=0;j<n;j+=1)
            {
                if(isSubfolder(folder[i],folder[j]) && i!=j)
                {
                    rslt.push_back(folder[j]);
                }
            }
        }
        for(int i=0;i<rslt.size();i++)
        {
            for(int j=0;j<n;j++)
            {
                if(rslt[i] == folder[j])
                {
                    folder.erase(remove(folder.begin(), folder.end(),rslt[i]), folder.end());
                }
            }
        }
        return folder;
    }
};

//this approach will reach TLE So optimised version for it 
//Lexicographical Sorting + Greedy Prefix Skipping

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        int n = folder.size();
        vector<string> rslt;
        for(int i=0;i<n;i++)
        {
           if(rslt.empty() || folder[i].find(rslt.back()+'/') != 0)
           {
                rslt.push_back(folder[i]);
           }
        }
        return rslt;
    }
};