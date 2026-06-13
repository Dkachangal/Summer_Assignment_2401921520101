#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) return s;
        if (s.length() == 2) {
            if (s[0] == s[1]) return s;
            else return s.substr(0, 1);
        }
        string longest = s.substr(0, 1);

        int center = s.length()/2;
        int left = center-1;
        int right = center + 1;
        if (s.length() %2 == 0) right = center;

        while (center >= 0) {
            left = center -1;
            right = (s.length() % 2 == 0) ? center: center +1;

            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left +1 > longest.length()) {
                    longest = s.substr(left, right - left +1);
                }
                left --;
                right++;
            }
            center--;
        }


        center = s.length()/2;
        while (center >= 0) {
            left = center;
            right = (s.length() % 2 == 0) ? center: center +1;

            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left +1 > longest.length()) {
                    longest = s.substr(left, right - left +1);
                }
                left --;
                right++;
            }
            center--;
        }

        center = (s.length() / 2) +1;
        while (center < s.length()) {
            left = center;
            right = (s.length() % 2 == 0) ? center: center +1;

            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left + 1 > longest.length()) {
                    longest = s.substr(left, right - left +1);
                }
                left--;
                right++;
            }
            center ++;
        }

        center = (s.length() / 2) +1;
        while (center < s.length()) {
            left = center -1;
            right = (s.length() % 2 == 0) ? center: center +1;

            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                if (right - left + 1 > longest.length()) {
                    longest = s.substr(left, right - left +1);
                }
                left--;
                right++;
            }
            center ++;
        }
        return longest;
    }
};

int main() {
    Solution solver;

    string s = "babad";

    string ans = solver.longestPalindrome(s);

    cout<<ans;

    return 0;
}