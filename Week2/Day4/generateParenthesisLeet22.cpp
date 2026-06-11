#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string str = "";
    vector<string> answerString;
    void second(int n, int open, int close, string *str) {
        if (open > n || close > n) return;
        if (open == close && open == n) {
            // found
            answerString.push_back(*str);
        }
        if (open < n) {
            str->push_back('(');
            second(n, open+1, close, str);
            str->pop_back();
        }
        if (close < open) {
            str->push_back(')');
            second(n, open, close+1, str);
            str->pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        int openNumber = 0;
        int closingNumber = 0;
        string str = "";
        second(n, 0, 0, &str);
        return answerString;
    }
};

int main() {
    Solution solver;
    int n = 3;

    vector<string> ans = solver.generateParenthesis(n);

    for (string s: ans) cout<< s<< "    ";

    return 0;
}