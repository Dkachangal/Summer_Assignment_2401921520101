#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        vector<int> a(26, 0);

        for (char x: s) a[x - 'a']++;
        for (char x: t) a[x - 'a']--;

        for (int i: a) if (i != 0) return false;
        return true;
    }
};


int main() {
    Solution solver;
        string s = "anagram", t = "nagaram";

        bool result = solver.isAnagram(s, t);
        cout<<result;

        return 0;
}