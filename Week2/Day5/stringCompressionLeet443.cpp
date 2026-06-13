#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        if (chars.size() == 1) return 1;
        int j = 1;

        for (int i=0; i<chars.size(); ) {
            
            if (j < chars.size() && chars[i] != chars[j]) {
                int currLen = j - i;
                s += chars[i];
                
                if (currLen > 9) {
                    string num = to_string(currLen);
                    for (auto x: num) s+= x;
                } else if (currLen != 1) {
                    s += (currLen + '0');
                }
                i = j;
                j = i+1;

            }
            else {
                // chars[i] == chars[j]
                if (j >= chars.size()) {
                    int currLen = j - i;
                    s += chars[i];

                    if (currLen > 9) {
                        string num = to_string(currLen);
                        for (auto x: num) s+= x;
                    } else if (currLen != 1) {

                        s += (currLen + '0');
                    }
                    break;
                }
                j++;
            }
        }
        for (char z: chars) chars.pop_back();
        for (char x: s) chars.push_back(x);
        return s.length();
    }
};

int main() {
    Solution solver;
    vector<char> chars = {'a','a','b','b','c','c','c'};
    int answer = solver.compress(chars);
    cout<<answer<<"\n";
    for (auto x: chars) cout<<x<<' ';

}