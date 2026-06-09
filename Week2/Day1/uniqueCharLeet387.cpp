#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> nums(26, 0);

        for (int i=0; i<s.length(); i++) {
            int idx = s[i] - 'a';
            nums[idx]++;
        }
        for (int i=0; i<s.length(); i++) {
            int idx = s[i] - 'a';
            if (nums[idx] == 1) {
                return i;
            }
        }
        return -1;
    }
};

int main() {
    Solution solver;

    string s = "leetcode";
    int result = solver.firstUniqChar(s);
    cout<< result;

    return 0;
}