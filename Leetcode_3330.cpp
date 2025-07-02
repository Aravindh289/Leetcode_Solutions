#include<iostream>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word) {
        if (word.empty()) return 0;
        
        int sze = 1;
        for (int i = 1; i < word.size(); i++) {
            if (word[i] != word[i - 1]) {
                sze += 1;
            }
        }
        return sze;
    }
};
int main() {
    Solution s;
    cout << s.possibleStringCount("aaabbcc") << endl; // Output: 3
    cout << s.possibleStringCount("aabba") << endl;   // Output: 4
    cout << s.possibleStringCount("a") << endl;       // Output: 1
}
