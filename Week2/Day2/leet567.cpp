#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkInInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) return false;
        
        vector<int> s1_count(26, 0);
        vector<int> s2_count(26, 0);
        
        for (int i = 0; i < s1.length(); i++) {
            s1_count[s1[i] - 'a']++;
            s2_count[s2[i] - 'a']++;
        }
        
        if (s1_count == s2_count) return true;
        
        for (int i = s1.length(); i < s2.length(); i++) {
            s2_count[s2[i] - 'a']++;
            s2_count[s2[i - s1.length()] - 'a']--;
            
            if (s1_count == s2_count) return true;
        }
        
        return false;
    }
};