#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack <char> brackets;

        for (char c: s) {
            if (c == '(') brackets.push(c);
            else if (c == '{') brackets.push(c);
            else if (c == '[') brackets.push(c);

            else if (c == ')') {
                if (!brackets.empty() && brackets.top() == '(') brackets.pop();
                else return false;
            }
            else if (c == '}') {
                if (!brackets.empty() && brackets.top() == '{') brackets.pop();
                else return false;
            }
            else if (c == ']') {
                if (!brackets.empty() && brackets.top() == '[') brackets.pop();
                else return false;
            }
        }
        if (brackets.empty()) return true;
        else return false;
    }
};

int main() {
    Solution solver;
    string testInput = "{[]} ()";
    
    if (solver.isValid(testInput)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}