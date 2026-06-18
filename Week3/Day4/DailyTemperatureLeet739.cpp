#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> idx;
        vector<int> warmDays(temperatures.size());

        for (int i=0; i<temperatures.size(); i++) {
            if (idx.empty()) {
                idx.push(i);
            }
            if (i+1 < temperatures.size()) {
                int tos = idx.top();

                if(temperatures[i+1] <= temperatures[idx.top()]) {
                    idx.push(i+1);
                    continue;
                } else {
                    while (!idx.empty() && temperatures[idx.top()] < temperatures[i+1]) {
                        warmDays[idx.top()] = i+1 - idx.top();
                        idx.pop();
                    }
                    idx.push(i+1);
                } 
            } else {
                warmDays[temperatures.size()-1] = 0;
            }
        }
        return warmDays;
    }
};

int main() {
    Solution solver;
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    
    vector<int> result = solver.dailyTemperatures(temperatures);
    
    for (int days : result) {
        cout << days << " ";
    }
    cout << endl;
    
    return 0;
}