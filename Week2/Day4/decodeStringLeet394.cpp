#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


class Solution {
public:
    string decodeString(string s) {
        // MY APPROACH - recursion
        
        // Traverse, mark st = the index of the latest [
        // mark end as the first ]
        // now traverse it, read whats there

        // BASE CASE HERE
        // If after traverse, no st and end found 
        // i.e. no [] present, return s;


        // eg int newStr = 5[c] => ccccc
        // now reCreate s => 
        // traverse s from 0 till st-1, push it in tempS
        // push newStr in tempS
        // traverse s from end +1 till s.length(), and push in tempS;
        // s = tempS;
        
        // return s;

        int st = 31;
        int end = 31;

        for (int i=0; i<s.length(); i++) {
            if (s[i] == '[') st = i;
            if (s[i] == ']') {
                end = i;
                break;
            }
        }
        // BASE CASE
        if (st == 31 || end == 31) return s;

        string newStr = "";
        string innerStr = "";
        string number = "";
        int x = 0;
        int tempSt = st-1;

        while (tempSt >= 0 && s[tempSt] - '0' >= 0 && s[tempSt] - '0' <= 9) {
            number += s[tempSt];
            tempSt--;
        }
        int len = number.length()-1;
        // reverse tempSt
        reverse(number.begin(), number.end());
        int num;
        if (number.length() == 1) num = number[0] - '0';
        else num = stoi(number);

        while (num > 0) {
            for (int i=st+1; i<end && i<s.length(); i++) {
                innerStr += s[i];
            }
            num--;
        }

        // modifying s
        string tempS = "";
        for (int i=0; i<=tempSt && i<s.length(); i++) {
            tempS += s[i];
        }
        tempS += innerStr;
        for (int i=end+1; i<s.length(); i++) {
            tempS += s[i];
        }
        s = tempS;
        return decodeString(s);
    }
};

int main() {
    Solution solver;

    string s = "3[a]2[bc]";
    string ans = solver.decodeString(s);
    cout<<ans;

    return 0;
}