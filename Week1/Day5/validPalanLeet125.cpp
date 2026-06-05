#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // lower str
        // while st <= end
        // if not alpha-numeric -> ignore
        // check if str[st] == str[end]
        // if not equal return false else return true

        if (s.length() == 0) {
            return true;
        }
        int st = 0, end = s.length() -1;

         std::transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        while (st <= end) {
            if (isalnum(s[st]) == false) {
                // this isalnum is used to check if a char is alpha numeric or not.
                st++;
                continue;
            } 
            if (isalnum(s[end]) == false) {
                end--;
                continue;
            }

            if (s[st] == s[end]) {
                st++;
                end--;
            } else {
                return false;
            }
        }
        return true;

    }
};

int main() {
    Solution solver;
    
    string s = "A man, a plan, a canal: Panama";
    bool result = solver.isPalindrome(s);
    cout << "Is the string a palindrome? " << (result ? "Yes" : "No") << endl;
    return 0;
}