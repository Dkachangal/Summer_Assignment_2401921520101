#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        vector<vector<string>> mainStr;

        for (int i = 0; i < strs.size(); i++) {
            string str = strs[i];
            
            vector<int> freq(26, 0);

            for (int j = 0; j < str.length(); j++) {
                int idx = str[j] - 'a';
                freq[idx]++;
            }
            mp[freq].push_back(str);
        }

        for (auto &pair : mp) {
            mainStr.push_back(pair.second);
        }
        return mainStr;
    }
};

int main() {
    Solution solver;
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    
    vector<vector<string>> ans = solver.groupAnagrams(strs);

    cout << "Grouped Anagrams:\n";
    cout << "[ \n";
    for (int i = 0; i < ans.size(); i++) {
        cout << "  [ ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << "\"" << ans[i][j] << "\"";
            if (j < ans[i].size() - 1) cout << ", ";
        }
        cout << " ]";
        if (i < ans.size() - 1) cout << ",";
        cout << "\n";
    }
    cout << "]\n";

    return 0;
}