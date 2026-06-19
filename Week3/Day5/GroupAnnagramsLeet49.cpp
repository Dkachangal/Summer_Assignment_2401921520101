#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<vector<int>, vector<string>> mp;
        vector<vector<string>> mainStr;

        for (int i=0; i<strs.size(); i++) {
            string str = strs[i];
            
            vector<int> freq(26, 0);

            for (int j=0; j<str.length(); j++) {
                int idx = str[j] - 'a';
                freq[idx]++;
            }
            mp[freq].push_back(str);
        }
        for (auto const& pair : mp) {
            mainStr.push_back(pair.second);
        }
        return mainStr;
    }
};

int main() {
    Solution solver;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<vector<string>> result = solver.groupAnagrams(strs);
    
    for (const auto& group : result) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}