#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int j =0;

        for (int i=0; i<s.length(); i++) {
            if (s[i] == ' ' || i == s.length()-1) {
                // space encountered
                // word index - [j, i-1] inclusive
                // swapping
                int end = i-1;
                if (i == s.length()-1) end = i;
                while (j < end && j <s.length() && end < s.length()) {
                    swap(s[j], s[end]);
                    j++;
                    end--;
                }
                j = i+1;
            }
        }
        return s;
    }
};

int main() {
    Solution solver;

    string s = "Let's take LeetCode contest";
    string ans = solver.reverseWords(s);

    cout<<ans;
    return 0;
}