#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    char nextChar(char c) {
        return c == 'z' ? 'a' : c + 1;
    }

    char kthCharacter(int k) {
        string word = "a";
        while (word.size() <= k) {
            string toadd = "";
            for (char c : word) {
                toadd += nextChar(c);
            }
            word += toadd;
        }
        return word[k - 1];
    }
};
int main() {
    Solution sol;

    int k = 10; 
    char result = sol.kthCharacter(k);

    cout << "The " << k << "th character is: " << result << endl;

    return 0;
}
