#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int st = 0;
        int end = s.size()-1;

        while (st < end) {
            char temp = s[st];
            s[st] = s[end];
            s[end] = temp;
            st++;
            end--;
        }

    }
};

int main() {
    Solution solver;
    
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    
    solver.reverseString(s);
    
    cout << "Reversed String: ";
    for (char c : s) {
        cout << c;
    }
    cout << endl; 
    
    return 0;   
}