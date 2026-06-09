#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> letters(26, 0);

        for (int i=0; i<magazine.length(); i++) {
            int idx = magazine[i] - 'a';
            letters[idx]++;
        }

        for (int i=0; i<ransomNote.length(); i++) {
            int idx = ransomNote[i] - 'a';
            letters[idx]--;
        }
        
        for (int i=0; i<26; i++) {
            if (letters[i] < 0) return false;
        }
        return true;
    }
};

int main() {
    Solution solver;

    string ransomNote = "a", magazine = "b";
    bool result = solver.canConstruct(ransomNote, magazine);
    cout<< result;

    return 0;
}