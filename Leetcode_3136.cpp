class Solution {
public:
    bool isValid(string word) {
        bool iisdigit = false, isvowel = false, isconsonant = false;
        int length = word.size();

        if (length < 3) {
            return false;
        }

        for (int i = 0; i < length; i++) {
            char ch = word[i];

            if (isalpha(ch)) {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                    ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                    isvowel = true;
                } else {
                    isconsonant = true;
                }
            } 
            else if (isdigit(ch)) {
                iisdigit = true;
            } 
            else {
                return false;
            }
        }

        return isvowel && isconsonant;
    }
};
