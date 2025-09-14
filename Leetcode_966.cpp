//brute force approach
class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    bool isequals(string a, string b) {
        if (a.size() != b.size()) return false;
        for (int i = 0; i < a.size(); i++) {
            char x = tolower(a[i]);
            char y = tolower(b[i]);
            if (x == y) continue;
            if (isVowel(x) && isVowel(y)) continue;
            return false;
        }
        return true;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        int n = wordlist.size();
        int m = queries.size();
        vector<string> v;
        for (int i = 0; i < m; i++) {
            string ck = queries[i];
            bool done = false;
            //crt match
            for (int j = 0; j < n; j++) 
            {
                if (wordlist[j] == ck) {
                    v.push_back(wordlist[j]);
                    done = true;
                    break;
                }
            }
            //partial match
            if (!done) {
                string d_ck = ck;
                transform(d_ck.begin(), d_ck.end(), d_ck.begin(), ::tolower);
                for (int j = 0; j < n; j++) {
                    string doop = wordlist[j];
                    transform(doop.begin(), doop.end(), doop.begin(), ::tolower);
                    if (doop == d_ck) 
                    {
                        v.push_back(wordlist[j]);
                        done = true;
                        break;
                    }
                }
            }
            //vowel match
            if (!done)
            {
            for(int j=0;j<n;j++)
            {
                if(isequals(ck,wordlist[j]))
                {
                    v.push_back(wordlist[j]);
                    done = true;
                    break;
                }
            }
            }
            //no match
            if(!done)
            {
               v.push_back("");
            }
        }
        return v;
    }
};
//will reach tle ....
