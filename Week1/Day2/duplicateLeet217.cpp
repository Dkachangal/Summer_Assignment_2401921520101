#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int x: nums) s.insert(x);
        if (s.size() != nums.size()) return true;
        return false;
    }
};

int main() {
    Solution solver;
    
    vector<int> nums = {1,2,3,1};
    
    bool hasDuplicate = solver.containsDuplicate(nums);
    
    cout << "Contains Duplicate: " << (hasDuplicate ? "true" : "false") << endl; 
    
    return 0;
}