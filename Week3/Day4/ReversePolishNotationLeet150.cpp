#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int toInt(string c) {
        return stoi(c);
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;

        for (int i=0; i<tokens.size(); i++) {
            string current = tokens[i];
            if (current != "+" && current != "-" && current != "*" && current != "/") {
                // number 
                stk.push(stoi(current));
            }
            else {
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();

                // now compute
                if (tokens[i] == "*") {
                    stk.push(num1 * num2);
                } else if (tokens[i] == "/") {
                    stk.push(num2 / num1);
                } else if (tokens[i] == "+") {
                    stk.push(num1 + num2);
                } else {
                    // subtract
                    stk.push(num2 - num1);
                }
            }
        }
            // string ans = stk.top();
            // stk.pop();
            // int numAns = stoi(ans);
            int numAns = stk.top();
            stk.pop();
            return numAns;
    }
};

int main() {
    Solution solver;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << solver.evalRPN(tokens) << endl;
    return 0;
}