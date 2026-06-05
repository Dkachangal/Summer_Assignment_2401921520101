#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        string longestPrefix = strs[0];


        for (int i=1; i<strs.size(); i++) {
            int j = 0;
            while (j<longestPrefix.length() && j<strs[i].length() && strs[i][j] == longestPrefix[j]) {
                j++;
            }
            longestPrefix = longestPrefix.substr(0, j);
            if (longestPrefix.length() == 0) return "";
        }
        return longestPrefix;
    }
};

int main() {
    Solution solver;
    
    vector<string> strs = {"flower", "flow", "flight"};
    
    string result = solver.longestCommonPrefix(strs);
    
    cout << "Longest Common Prefix: " << result << endl; 
    
    return 0;   
}